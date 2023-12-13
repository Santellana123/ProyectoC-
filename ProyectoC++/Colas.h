#pragma once

namespace ProyectoC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Resumen de Colas
	/// </summary>
	ref class Cola
	{
	private:
		System::Collections::Generic::Queue<int>^ elementos;

	public:
		Cola()
		{
			elementos = gcnew System::Collections::Generic::Queue<int>();
		}

		// Función para agregar un elemento al final de la cola (enqueue)
		void Enqueue(int elemento)
		{
			elementos->Enqueue(elemento);
		}

		// Función para eliminar y obtener el elemento del frente de la cola (dequeue)
		int Dequeue()
		{
			if (elementos->Count == 0) {
				// Manejo de error si la cola está vacía
				throw gcnew InvalidOperationException("La cola está vacía.");
			}

			return elementos->Dequeue();
		}

		// Función para verificar si la cola está vacía
		bool EstaVacia()
		{
			return elementos->Count == 0;
		}

		// Función para obtener el elemento del frente de la cola sin eliminarlo
		int Peek()
		{
			if (elementos->Count == 0) {
				// Manejo de error si la cola está vacía
				throw gcnew InvalidOperationException("La cola está vacía.");
			}

			return elementos->Peek();
		}

		// Función para obtener todos los elementos de la cola
		array<int>^ ObtenerElementos()
		{
			return elementos->ToArray();
		}
	};

	public ref class Colas : public System::Windows::Forms::Form
	{
	public:
		Cola^ miCola;
		Colas(void)
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
		~Colas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEnqueue;
	private: System::Windows::Forms::Button^ btnDequeue;
	private: System::Windows::Forms::ListBox^ listBoxCola;
	private: System::Windows::Forms::TextBox^ txtValor;
	protected:


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
			this->btnEnqueue = (gcnew System::Windows::Forms::Button());
			this->btnDequeue = (gcnew System::Windows::Forms::Button());
			this->listBoxCola = (gcnew System::Windows::Forms::ListBox());
			this->txtValor = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnEnqueue
			// 
			this->btnEnqueue->Location = System::Drawing::Point(0, 0);
			this->btnEnqueue->Name = L"btnEnqueue";
			this->btnEnqueue->Size = System::Drawing::Size(75, 23);
			this->btnEnqueue->TabIndex = 0;
			this->btnEnqueue->Text = L"button1";
			this->btnEnqueue->UseVisualStyleBackColor = true;
			this->btnEnqueue->Click += gcnew System::EventHandler(this, &Colas::btnEnqueue_Click);
			// 
			// btnDequeue
			// 
			this->btnDequeue->Location = System::Drawing::Point(0, 72);
			this->btnDequeue->Name = L"btnDequeue";
			this->btnDequeue->Size = System::Drawing::Size(75, 23);
			this->btnDequeue->TabIndex = 1;
			this->btnDequeue->Text = L"button2";
			this->btnDequeue->UseVisualStyleBackColor = true;
			this->btnDequeue->Click += gcnew System::EventHandler(this, &Colas::btnDequeue_Click);
			// 
			// listBoxCola
			// 
			this->listBoxCola->FormattingEnabled = true;
			this->listBoxCola->Location = System::Drawing::Point(51, 168);
			this->listBoxCola->Name = L"listBoxCola";
			this->listBoxCola->Size = System::Drawing::Size(370, 147);
			this->listBoxCola->TabIndex = 2;
			// 
			// txtValor
			// 
			this->txtValor->Location = System::Drawing::Point(113, 35);
			this->txtValor->Name = L"txtValor";
			this->txtValor->Size = System::Drawing::Size(100, 20);
			this->txtValor->TabIndex = 3;
			// 
			// Colas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 377);
			this->Controls->Add(this->txtValor);
			this->Controls->Add(this->listBoxCola);
			this->Controls->Add(this->btnDequeue);
			this->Controls->Add(this->btnEnqueue);
			this->Name = L"Colas";
			this->Text = L"Colas";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnEnqueue_Click(System::Object^ sender, System::EventArgs^ e) {
		int valor;
		if (Int32::TryParse(txtValor->Text, valor)) {
			miCola->Enqueue(valor);
			ActualizarListBox();
		}
		else {
			MessageBox::Show("Ingrese un valor válido.");
		}
	}
	private: System::Void btnDequeue_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			miCola->Dequeue();
			ActualizarListBox();
		}
		catch (InvalidOperationException^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
		   void ActualizarListBox() {
			   listBoxCola->Items->Clear();
			   array<int>^ elementos = miCola->ObtenerElementos();
			   for each (int elemento in elementos) {
				   listBoxCola->Items->Add(elemento);
			   }
		   }
};
}
