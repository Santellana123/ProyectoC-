#pragma once
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_set>
namespace ProyectoC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	ref class NodoGrafo
	{
	public:
		int Valor;
		List<NodoGrafo^>^ Vecinos;

		NodoGrafo(int valor)
		{
			Valor = valor;
			Vecinos = gcnew List<NodoGrafo^>();
		}
	};

	// Definición de la clase Grafo
	ref class Grafo
	{
	private:
		List<NodoGrafo^>^ nodos;

	public:
		Grafo()
		{
			nodos = gcnew List<NodoGrafo^>();
		}

		// Agregar un vértice al grafo
		void AgregarVertice(int valor)
		{
			NodoGrafo^ nuevoNodo = gcnew NodoGrafo(valor);
			nodos->Add(nuevoNodo);
		}

		// Conectar dos vértices mediante una arista
		void AgregarArista(int valorInicio, int valorFin)
		{
			NodoGrafo^ inicio = ObtenerNodo(valorInicio);
			NodoGrafo^ fin = ObtenerNodo(valorFin);

			if (inicio != nullptr && fin != nullptr)
			{
				inicio->Vecinos->Add(fin);
				fin->Vecinos->Add(inicio);
			}
		}

		// Obtener un nodo por su valor
		NodoGrafo^ ObtenerNodo(int valor)
		{
			for each (NodoGrafo ^ nodo in nodos)
			{
				if (nodo->Valor == valor)
				{
					return nodo;
				}
			}
			return nullptr;
		}

		// Realizar un recorrido DFS desde un nodo
		void DFS(int valorInicio)
		{
			NodoGrafo^ inicio = ObtenerNodo(valorInicio);
			if (inicio != nullptr)
			{
				HashSet<NodoGrafo^>^ visitados = gcnew HashSet<NodoGrafo^>();
				DFSRecursivo(inicio, visitados);
			}
		}

		// Función auxiliar para realizar el recorrido DFS recursivo
		void DFSRecursivo(NodoGrafo^ nodo, HashSet<NodoGrafo^>^ visitados)
		{
			if (!visitados->Contains(nodo))
			{
				Console::WriteLine(nodo->Valor);
				visitados->Add(nodo);

				for each (NodoGrafo ^ vecino in nodo->Vecinos)
				{
					DFSRecursivo(vecino, visitados);
				}
			}
		}

		// Realizar un recorrido BFS desde un nodo
		void BFS(int valorInicio)
		{
			NodoGrafo^ inicio = ObtenerNodo(valorInicio);
			if (inicio != nullptr)
			{
				HashSet<NodoGrafo^>^ visitados = gcnew HashSet<NodoGrafo^>();
				System::Collections::Generic::Queue<NodoGrafo^>^ cola = gcnew System::Collections::Generic::Queue<NodoGrafo^>();

				cola->Enqueue(inicio);
				visitados->Add(inicio);

				while (cola->Count > 0)
				{
					NodoGrafo^ nodoActual = cola->Dequeue();
					Console::WriteLine(nodoActual->Valor);

					for each (NodoGrafo ^ vecino in nodoActual->Vecinos)
					{
						if (!visitados->Contains(vecino))
						{
							cola->Enqueue(vecino);
							visitados->Add(vecino);
						}
					}
				}
			}
		}
	};

	/// <summary>
	/// Resumen de Grafos
	/// </summary>
	public ref class Grafos : public System::Windows::Forms::Form
	{
	public:
		Grafo^ miGrafo;
		Grafos(void)
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
		~Grafos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnAgregarVertice;
	private: System::Windows::Forms::Button^ btnConectarVertices;
	private: System::Windows::Forms::Button^ btnDFS;
	private: System::Windows::Forms::Button^ btnBFS;
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
			this->btnAgregarVertice = (gcnew System::Windows::Forms::Button());
			this->btnConectarVertices = (gcnew System::Windows::Forms::Button());
			this->btnDFS = (gcnew System::Windows::Forms::Button());
			this->btnBFS = (gcnew System::Windows::Forms::Button());
			this->txtValor = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnAgregarVertice
			// 
			this->btnAgregarVertice->Location = System::Drawing::Point(12, 38);
			this->btnAgregarVertice->Name = L"btnAgregarVertice";
			this->btnAgregarVertice->Size = System::Drawing::Size(75, 23);
			this->btnAgregarVertice->TabIndex = 0;
			this->btnAgregarVertice->Text = L"button1";
			this->btnAgregarVertice->UseVisualStyleBackColor = true;
			this->btnAgregarVertice->Click += gcnew System::EventHandler(this, &Grafos::btnAgregarVertice_Click);
			// 
			// btnConectarVertices
			// 
			this->btnConectarVertices->Location = System::Drawing::Point(12, 67);
			this->btnConectarVertices->Name = L"btnConectarVertices";
			this->btnConectarVertices->Size = System::Drawing::Size(75, 23);
			this->btnConectarVertices->TabIndex = 1;
			this->btnConectarVertices->Text = L"button1";
			this->btnConectarVertices->UseVisualStyleBackColor = true;
			this->btnConectarVertices->Click += gcnew System::EventHandler(this, &Grafos::btnConectarVertices_Click);
			// 
			// btnDFS
			// 
			this->btnDFS->Location = System::Drawing::Point(12, 96);
			this->btnDFS->Name = L"btnDFS";
			this->btnDFS->Size = System::Drawing::Size(75, 23);
			this->btnDFS->TabIndex = 2;
			this->btnDFS->Text = L"button1";
			this->btnDFS->UseVisualStyleBackColor = true;
			this->btnDFS->Click += gcnew System::EventHandler(this, &Grafos::btnDFS_Click);
			// 
			// btnBFS
			// 
			this->btnBFS->Location = System::Drawing::Point(12, 125);
			this->btnBFS->Name = L"btnBFS";
			this->btnBFS->Size = System::Drawing::Size(75, 23);
			this->btnBFS->TabIndex = 3;
			this->btnBFS->Text = L"button1";
			this->btnBFS->UseVisualStyleBackColor = true;
			this->btnBFS->Click += gcnew System::EventHandler(this, &Grafos::btnBFS_Click);
			// 
			// txtValor
			// 
			this->txtValor->Location = System::Drawing::Point(108, 38);
			this->txtValor->Name = L"txtValor";
			this->txtValor->Size = System::Drawing::Size(100, 20);
			this->txtValor->TabIndex = 4;
			// 
			// Grafos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->txtValor);
			this->Controls->Add(this->btnBFS);
			this->Controls->Add(this->btnDFS);
			this->Controls->Add(this->btnConectarVertices);
			this->Controls->Add(this->btnAgregarVertice);
			this->Name = L"Grafos";
			this->Text = L"Grafos";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAgregarVertice_Click(System::Object^ sender, System::EventArgs^ e) {
		int valor;
		if (Int32::TryParse(txtValor->Text, valor))
		{
			miGrafo->AgregarVertice(valor);
		}
		else
		{
			MessageBox::Show("Ingrese un valor válido.");
		}
	}
private: System::Void btnConectarVertices_Click(System::Object^ sender, System::EventArgs^ e) {
	int valorInicio, valorFin;
	if (Int32::TryParse(txtValor->Text, valorInicio))
	{
		if (Int32::TryParse(Microsoft::VisualBasic::Interaction::InputBox("Ingrese el valor del segundo vértice:", "Conectar Vértices"), valorFin))
		{
			miGrafo->AgregarArista(valorInicio, valorFin);
		}
		else
		{
			MessageBox::Show("Ingrese un valor válido para el segundo vértice.");
		}
	}
	else
	{
		MessageBox::Show("Ingrese un valor válido para el primer vértice.");
	}
}
private: System::Void btnDFS_Click(System::Object^ sender, System::EventArgs^ e) {
	int valorInicio;
	if (Int32::TryParse(txtValor->Text, valorInicio))
	{
		miGrafo->DFS(valorInicio);
	}
	else
	{
		MessageBox::Show("Ingrese un valor válido.");
	}
}
private: System::Void btnBFS_Click(System::Object^ sender, System::EventArgs^ e) {
	int valorInicio;
	if (Int32::TryParse(txtValor->Text, valorInicio))
	{
		miGrafo->BFS(valorInicio);
	}
	else
	{
		MessageBox::Show("Ingrese un valor válido.");
	}
}
};
}
