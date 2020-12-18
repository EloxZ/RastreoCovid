#pragma once
#include <string>
#include <list>
#include <array>


namespace ProjectCovid {

	using namespace System;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	ref class BDConn
	{
		
		
		String^ connectionInfo = "datasource=ingreq2021-mysql.cobadwnzalab.eu-central-1.rds.amazonaws.com;port=3306;username=grupo11;password=villalbaaguayo2020;database=apsgrupo11";
		MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
		MySqlDataReader^ dataReader;

	public: 
		BDConn()
		{

		}

		/*list Select(string consultaSelect)
		{

			if (consultaSelect.Length == 0) return null;
			if (consultaSelect.ToUpper().IndexOf("SELECT") == -1) return null;
			if (consultaSelect.ToUpper().IndexOf("DROP") > -1) return null;

			List<object[]> res = new List<object[]>();
			MySqlConnection conexion = new MySqlConnection(cadenaConexion);
			MySqlCommand comando = new MySqlCommand(consultaSelect, conexion);

			conexion.Open();
			MySqlDataReader reader = comando.ExecuteReader();

			while (reader.Read())
			{
				int numColumnas = reader.FieldCount;
				Object[] fila = new object[numColumnas];
				for (int i = 0; i < numColumnas; ++i) fila[i] = reader[i];
				res.Add(fila);
			}

			conexion.Close();


			return res;
		}

		

		std::list<Object[]> Select(String^ querySelect)
		{
			if (!querySelect->Length == 0)
			{
				try {
					String^ SQLQuery = querySelect;
					MySqlCommand^ connCmd = gcnew MySqlCommand(SQLQuery, conn);
					conn->Open();
					MySqlDataReader^ reader = connCmd->ExecuteReader();

					while (reader->Read())
					{
						int numColumnas = reader->FieldCount;
						Object[numColumnas] fila;
					}
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
		}*/


		void Update(String^ queryUpdate)
		{
			if (!queryUpdate->Length == 0)
			{
				try {
					String^ SQLQuery = queryUpdate;
					MySqlCommand^ connCmd = gcnew MySqlCommand(SQLQuery, conn);
					conn->Open();
					dataReader = connCmd->ExecuteReader();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
		}

		void Delete(String^ queryDelete)
		{
			if (!queryDelete->Length == 0)
			{
				try {
					String^ SQLQuery = queryDelete;
					MySqlCommand^ connCmd = gcnew MySqlCommand(SQLQuery, conn);
					conn->Open();
					dataReader = connCmd->ExecuteReader();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
		}

		void Insert(String^ queryInsert)
		{
			if (!queryInsert->Length==0)
			{
				try {
					String^ SQLQuery = queryInsert;
					MySqlCommand^ connCmd = gcnew MySqlCommand(SQLQuery, conn);
					conn->Open();
					dataReader = connCmd->ExecuteReader();
				}
				catch (Exception^ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
		}



	};

}