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
	/// Resumen de FormListaEnlazada
	/// </summary>
	generic <typename T>
	ref class Nodo
	{
	public:
		T Dato;
		Nodo^ Siguiente;

		Nodo(T valor)
		{
			Dato = valor;
			Siguiente = nullptr;
		}
	};

	// Lista enlazada simple
	generic <typename T>
	ref class ListaEnlazada
	{
	private:
		Nodo<T>^ cabeza;

	public:
		ListaEnlazada()
		{
			cabeza = nullptr;
		}

		// Agregar un elemento al final de la lista
		void AgregarAlFinal(T valor)
		{
			Nodo<T>^ nuevoNodo = gcnew Nodo<T>(valor);

			if (cabeza == nullptr)
			{
				cabeza = nuevoNodo;
			}
			else
			{
				Nodo<T>^ temp = cabeza;
				while (temp->Siguiente != nullptr)
				{
					temp = temp->Siguiente;
				}
				temp->Siguiente = nuevoNodo;
			}
		}

		// Eliminar el primer elemento de la lista
		void EliminarDelInicio()
		{
			if (cabeza != nullptr)
			{
				Nodo<T>^ temp = cabeza;
				cabeza = cabeza->Siguiente;
				delete temp;
			}
		}

		// Obtener todos los elementos de la lista
		List<T>^ ObtenerElementos()
		{
			List<T>^ elementos = gcnew List<T>();
			Nodo<T>^ temp = cabeza;

			while (temp != nullptr)
			{
				elementos->Add(temp->Dato);
				temp = temp->Siguiente;
			}

			return elementos;
		}
	};
	public ref class FormListaEnlazada : public System::Windows::Forms::Form
	{
	public:
		ListaEnlazada<int>^ miLista;
		ListBox^ listBox;
		Button^ btnAgregar;
		Button^ btnEliminar;
		FormListaEnlazada(void)
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
		~FormListaEnlazada()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ListBox^ listBox;
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
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(24, 52);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(75, 23);
			this->btnAgregar->TabIndex = 0;
			this->btnAgregar->Text = L"button1";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &FormListaEnlazada::btnAgregar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(227, 52);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(75, 23);
			this->btnEliminar->TabIndex = 1;
			this->btnEliminar->Text = L"button1";
			this->btnEliminar->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(105, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// listBox
			// 
			this->listBox->FormattingEnabled = true;
			this->listBox->Location = System::Drawing::Point(85, 128);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(198, 147);
			this->listBox->TabIndex = 3;
			// 
			// FormListaEnlazada
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(441, 349);
			this->Controls->Add(this->listBox);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnAgregar);
			this->Name = L"FormListaEnlazada";
			this->Text = L"FormListaEnlazada";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
		int valor;
		if (Int32::TryParse(textBox1->Text, valor))
		{
			miLista->AgregarAlFinal(valor);
			ActualizarListBox();
		}
		else
		{
			MessageBox::Show("Ingrese un valor válido.");
		}
	}
		   void ActualizarListBox()
        {
            listBox->Items->Clear();
            List<int>^ elementos = miLista->ObtenerElementos();
            for each (int elemento in elementos)
            {
                listBox->Items->Add(elemento);
            }
        }
	};
}
