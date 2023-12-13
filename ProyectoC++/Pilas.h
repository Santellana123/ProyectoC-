#pragma once

namespace ProyectoC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	
	
	ref class Pila
	{
	private:
		List<int>^ elementos;

	public:
		Pila()
		{
			elementos = gcnew List<int>();
		}

		// Función para agregar un elemento a la pila (push)
		void Push(int elemento)
		{
			elementos->Add(elemento);
		}

		// Función para eliminar y obtener el elemento superior de la pila (pop)
		int Pop()
		{
			if (elementos->Count == 0) {
				// Manejo de error si la pila está vacía
				throw gcnew InvalidOperationException("La pila está vacía.");
			}

			int elemento = elementos[elementos->Count - 1];
			elementos->RemoveAt(elementos->Count - 1);
			return elemento;
		}

		// Función para verificar si la pila está vacía
		bool EstaVacia()
		{
			return elementos->Count == 0;
		}

		// Función para obtener el elemento superior de la pila sin eliminarlo
		int Peek()
		{
			if (elementos->Count == 0) {
				// Manejo de error si la pila está vacía
				throw gcnew InvalidOperationException("La pila está vacía.");
			}

			return elementos[elementos->Count - 1];
		}
		List<int>^ ObtenerElementos()
		{
			return elementos;
		}
	};
	/// <summary>
	/// Resumen de Pilas
	/// </summary>
	/// 
	public ref class Pilas : public System::Windows::Forms::Form
	{
	public:
		Pila^ miPila;
		Pilas(void)
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
		~Pilas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnPush;
	private: System::Windows::Forms::TextBox^ txtValor;
	private: System::Windows::Forms::Button^ btnPop;
	private: System::Windows::Forms::ListBox^ listBoxPila;

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
			this->btnPush = (gcnew System::Windows::Forms::Button());
			this->txtValor = (gcnew System::Windows::Forms::TextBox());
			this->btnPop = (gcnew System::Windows::Forms::Button());
			this->listBoxPila = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnPush
			// 
			this->btnPush->Location = System::Drawing::Point(12, 12);
			this->btnPush->Name = L"btnPush";
			this->btnPush->Size = System::Drawing::Size(75, 23);
			this->btnPush->TabIndex = 0;
			this->btnPush->Text = L"button1";
			this->btnPush->UseVisualStyleBackColor = true;
			this->btnPush->Click += gcnew System::EventHandler(this, &Pilas::btnPush_Click);
			// 
			// txtValor
			// 
			this->txtValor->Location = System::Drawing::Point(113, 12);
			this->txtValor->Name = L"txtValor";
			this->txtValor->Size = System::Drawing::Size(100, 20);
			this->txtValor->TabIndex = 1;
			// 
			// btnPop
			// 
			this->btnPop->Location = System::Drawing::Point(12, 53);
			this->btnPop->Name = L"btnPop";
			this->btnPop->Size = System::Drawing::Size(75, 23);
			this->btnPop->TabIndex = 2;
			this->btnPop->Text = L"button1";
			this->btnPop->UseVisualStyleBackColor = true;
			this->btnPop->Click += gcnew System::EventHandler(this, &Pilas::btnPop_Click);
			// 
			// listBoxPila
			// 
			this->listBoxPila->FormattingEnabled = true;
			this->listBoxPila->Location = System::Drawing::Point(45, 107);
			this->listBoxPila->Name = L"listBoxPila";
			this->listBoxPila->Size = System::Drawing::Size(384, 212);
			this->listBoxPila->TabIndex = 3;
			// 
			// Pilas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(611, 387);
			this->Controls->Add(this->listBoxPila);
			this->Controls->Add(this->btnPop);
			this->Controls->Add(this->txtValor);
			this->Controls->Add(this->btnPush);
			this->Name = L"Pilas";
			this->Text = L"Pilas";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnPush_Click(System::Object^ sender, System::EventArgs^ e) {
		int valor;
		if (Int32::TryParse(txtValor->Text, valor)) {
			miPila->Push(valor);
			ActualizarListBox();
		}
		else {
			MessageBox::Show("Ingrese un valor válido.");
		}
	}
	private: System::Void btnPop_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			miPila->Pop();
			ActualizarListBox();
		}
		catch (InvalidOperationException^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
		   void ActualizarListBox() {
			   listBoxPila->Items->Clear();
			   for each (int elemento in miPila->ObtenerElementos()) {
				   listBoxPila->Items->Add(elemento);
			   }
		   }
};
}
