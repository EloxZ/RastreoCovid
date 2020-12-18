#pragma once
#include <string>
#include <list>
namespace ProjectCovid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	ref class Persona
	{
	private:
		int id;
		String^ fisrtname;
		String^ lastname;

	public:
		Persona(int i, String^ u, String^ p) {
			id = i;
			fisrtname = u;
			lastname = p;
		}
		System::Int32 getId() {
			return this->id;
		}
		System::String^ getFistName() {
			return this->fisrtname;
		}
		System::String^ getLastName() {
			return this->lastname;
		}

		System::Data::DataSet^ amigos() {
			String^ SQLQuery = "(select ID2 from Friends where ID1 = "+this->id+") union (select ID1 from Friends where ID2 = "+this->id+");"; //seleccionar amigos
			String^ connectionInfo = "datasource=ingreq2021-mysql.cobadwnzalab.eu-central-1.rds.amazonaws.com;port=3306;username=grupo11;password=villalbaaguayo2020;database=apsgrupo11";
			MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
			MySqlDataAdapter^ adpt = gcnew MySqlDataAdapter(SQLQuery, conn);
			MySqlHelper^ SqlHelper = gcnew MySqlHelper();

			DataTable^ dataTable = SqlHelper->ExecuteDataset(connectionInfo, SQLQuery)->Tables[0];
			IList^ SourceLists = gcnew ArrayList();
			for (var index = 0; index < dataTable.Rows.Count; index++)
			{
				SourceLists.Add(new ShowInstitutes
					{
						InstituteName = Convert.ToString(dataTable.Rows[index]["Columnname"], CultureInfo.InvariantCulture),
						InstituteCity = Convert.ToString(dataTable.Rows[index]["Columnname"], CultureInfo.InvariantCulture),
						InstituteId = Convert.ToInt32(dataTable.Rows[index]["Columnname"], CultureInfo.InvariantCulture)
					});
			}

			DataSet^ dset = gcnew DataSet();
			adpt->Fill(dset);
			return dset;
		}

		System::Data::DataSet^ disponibles(DataSet^ amigos) {
			String^ SQLQuery = "select * from People where ID not in ((select ID2 from Friends where ID1 = "+this->id+") union (select ID1 from Friends where ID2 = " + this->id + ")) and ID != " + this->id + ";";//sacar todas las personas menos los amigos
			String^ connectionInfo = "datasource=ingreq2021-mysql.cobadwnzalab.eu-central-1.rds.amazonaws.com;port=3306;username=grupo11;password=villalbaaguayo2020;database=apsgrupo11";
			MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
			MySqlDataAdapter^ adpt = gcnew MySqlDataAdapter(SQLQuery, conn);

			DataSet^ dset = gcnew DataSet();
			adpt->Fill(dset);
			return dset;
		}

		System::String^ toString() {
			return (String^)this->id.ToString() + "; " + this->lastname + "; " + this->fisrtname;
		}
	};
}


