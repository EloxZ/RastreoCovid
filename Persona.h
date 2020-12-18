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
        String^ firstname;
        String^ lastname;

    public:
        Persona(int i, String^ u, String^ p) {
            id = i;
            firstname = u;
            lastname = p;
        }
        System::Int32 getId() {
            return this->id;
        }
        System::String^ getFirstName() {
            return this->firstname;
        }
        System::String^ getLastName() {
            return this->lastname;
        }
        Persona(int i)
        {
            try {
                String^ SQLQuery = "SELECT * FROM People WHERE ID = " + i.ToString() + ";";
                String^ connectionInfo = "datasource=ingreq2021-mysql.cobadwnzalab.eu-central-1.rds.amazonaws.com;port=3306;username=grupo11;password=villalbaaguayo2020;database=apsgrupo11";
                MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
               
                MySqlCommand^ connCmd = gcnew MySqlCommand(SQLQuery, conn);
              
                conn->Open();
                
                MySqlDataReader^ dr = connCmd->ExecuteReader();
                
                if (dr->Read())
                {
                    id = dr->GetInt32(0);
                    firstname = dr->GetString(1);
                    lastname = dr->GetString(2);
                    conn->Close();
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message);
            }

            
        }
    };
}

