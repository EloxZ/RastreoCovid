#pragma once


namespace ProjectCovid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Ventana principal del programa.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ gvPersonas;
	protected:

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Apellidos;
	private: System::Windows::Forms::Label^ labelPersonas;
	private: System::Windows::Forms::ListBox^ lbAmigos;
	private: System::Windows::Forms::ListBox^ lbDisponibles;
	private: System::Windows::Forms::Label^ labelAmigos;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btAmigoToDisponible;
	private: System::Windows::Forms::Button^ btDisponibleToAmigo;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->gvPersonas = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Apellidos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->labelPersonas = (gcnew System::Windows::Forms::Label());
			this->lbAmigos = (gcnew System::Windows::Forms::ListBox());
			this->lbDisponibles = (gcnew System::Windows::Forms::ListBox());
			this->labelAmigos = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btAmigoToDisponible = (gcnew System::Windows::Forms::Button());
			this->btDisponibleToAmigo = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvPersonas))->BeginInit();
			this->SuspendLayout();
			// 
			// gvPersonas
			// 
			this->gvPersonas->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->gvPersonas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gvPersonas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ID, this->Nombre,
					this->Apellidos
			});
			this->gvPersonas->Location = System::Drawing::Point(56, 90);
			this->gvPersonas->MultiSelect = false;
			this->gvPersonas->Name = L"gvPersonas";
			this->gvPersonas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->gvPersonas->Size = System::Drawing::Size(343, 319);
			this->gvPersonas->TabIndex = 0;
			this->gvPersonas->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// Nombre
			// 
			this->Nombre->HeaderText = L"Nombre";
			this->Nombre->Name = L"Nombre";
			this->Nombre->ReadOnly = true;
			// 
			// Apellidos
			// 
			this->Apellidos->HeaderText = L"Apellidos";
			this->Apellidos->Name = L"Apellidos";
			this->Apellidos->ReadOnly = true;
			// 
			// labelPersonas
			// 
			this->labelPersonas->AutoSize = true;
			this->labelPersonas->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPersonas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->labelPersonas->Location = System::Drawing::Point(177, 51);
			this->labelPersonas->Name = L"labelPersonas";
			this->labelPersonas->Size = System::Drawing::Size(108, 23);
			this->labelPersonas->TabIndex = 1;
			this->labelPersonas->Text = L"Personas";
			// 
			// lbAmigos
			// 
			this->lbAmigos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->lbAmigos->FormattingEnabled = true;
			this->lbAmigos->Location = System::Drawing::Point(448, 90);
			this->lbAmigos->Name = L"lbAmigos";
			this->lbAmigos->Size = System::Drawing::Size(160, 316);
			this->lbAmigos->TabIndex = 2;
			// 
			// lbDisponibles
			// 
			this->lbDisponibles->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->lbDisponibles->FormattingEnabled = true;
			this->lbDisponibles->Location = System::Drawing::Point(665, 90);
			this->lbDisponibles->Name = L"lbDisponibles";
			this->lbDisponibles->Size = System::Drawing::Size(160, 316);
			this->lbDisponibles->TabIndex = 3;
			// 
			// labelAmigos
			// 
			this->labelAmigos->AutoSize = true;
			this->labelAmigos->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAmigos->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->labelAmigos->Location = System::Drawing::Point(482, 51);
			this->labelAmigos->Name = L"labelAmigos";
			this->labelAmigos->Size = System::Drawing::Size(89, 23);
			this->labelAmigos->TabIndex = 4;
			this->labelAmigos->Text = L"Amigos";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->label1->Location = System::Drawing::Point(678, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 23);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Disponibles";
			// 
			// btAmigoToDisponible
			// 
			this->btAmigoToDisponible->Location = System::Drawing::Point(614, 106);
			this->btAmigoToDisponible->Name = L"btAmigoToDisponible";
			this->btAmigoToDisponible->Size = System::Drawing::Size(45, 36);
			this->btAmigoToDisponible->TabIndex = 6;
			this->btAmigoToDisponible->Text = L"-->";
			this->btAmigoToDisponible->UseVisualStyleBackColor = true;
			// 
			// btDisponibleToAmigo
			// 
			this->btDisponibleToAmigo->Location = System::Drawing::Point(614, 163);
			this->btDisponibleToAmigo->Name = L"btDisponibleToAmigo";
			this->btDisponibleToAmigo->Size = System::Drawing::Size(45, 36);
			this->btDisponibleToAmigo->TabIndex = 7;
			this->btDisponibleToAmigo->Text = L"<--";
			this->btDisponibleToAmigo->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(56, 22);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(884, 461);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btDisponibleToAmigo);
			this->Controls->Add(this->btAmigoToDisponible);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelAmigos);
			this->Controls->Add(this->lbDisponibles);
			this->Controls->Add(this->lbAmigos);
			this->Controls->Add(this->labelPersonas);
			this->Controls->Add(this->gvPersonas);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rastreo Covid-19";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvPersonas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ SQLQuery = "INSERT INTO People VALUES (123,'Pepe','Villuela')";
	String^ connectionInfo = "datasource=ingreq2021-mysql.cobadwnzalab.eu-central-1.rds.amazonaws.com;port=3306;username=grupo11;password=villalbaaguayo2020;database=apsgrupo11";
	MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
	MySqlCommand^ connCmd = gcnew MySqlCommand(SQLQuery, conn);
	MySqlDataReader^ dataReader;

	try {
		conn->Open();
		dataReader=connCmd->ExecuteReader();
	}
	catch (Exception^ex) {
		MessageBox::Show(ex->Message);
	}
}	
};
}
