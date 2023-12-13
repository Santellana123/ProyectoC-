#pragma once


namespace ProyectoC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class NodoArbol {
	public:
		int Valor;
		NodoArbol^ Izquierda;
		NodoArbol^ Derecha;

		NodoArbol(int valor) {
			Valor = valor;
			Izquierda = nullptr;
			Derecha = nullptr;
		}
	};
	ref class ArbolBinario {
	private:
		NodoArbol^ raiz;

	public:
		ArbolBinario() {
			raiz = nullptr;
		}

		void Insertar(int valor) {
			raiz = InsertarRec(raiz, valor);
		}

		NodoArbol^ InsertarRec(NodoArbol^ raizActual, int valor) {
			if (raizActual == nullptr) {
				return gcnew NodoArbol(valor);
			}

			if (valor < raizActual->Valor) {
				raizActual->Izquierda = InsertarRec(raizActual->Izquierda, valor);
			}
			else if (valor > raizActual->Valor) {
				raizActual->Derecha = InsertarRec(raizActual->Derecha, valor);
			}

			return raizActual;
		}

		void MostrarEnTreeView(TreeView^ treeView) {
			treeView->Nodes->Clear();
			MostrarEnTreeViewRec(raiz, treeView->Nodes);
		}

		void MostrarEnTreeViewRec(NodoArbol^ raizActual, TreeNodeCollection^ treeNodes) {
			if (raizActual != nullptr) {
				treeNodes->Add(gcnew TreeNode(raizActual->Valor.ToString()));
				MostrarEnTreeViewRec(raizActual->Izquierda, treeNodes[treeNodes->Count - 1]->Nodes);
				MostrarEnTreeViewRec(raizActual->Derecha, treeNodes[treeNodes->Count - 1]->Nodes);
			}
		}
		void Eliminar(int valor) {
			raiz = EliminarRec(raiz, valor);
		}

		NodoArbol^ EliminarRec(NodoArbol^ raizActual, int valor) {
			if (raizActual == nullptr) {
				return raizActual;
			}

			if (valor < raizActual->Valor) {
				raizActual->Izquierda = EliminarRec(raizActual->Izquierda, valor);
			}
			else if (valor > raizActual->Valor) {
				raizActual->Derecha = EliminarRec(raizActual->Derecha, valor);
			}
			else {
				// Nodo encontrado, realizar la eliminación
				if (raizActual->Izquierda == nullptr) {
					NodoArbol^ temp = raizActual->Derecha;
					delete raizActual;
					return temp;
				}
				else if (raizActual->Derecha == nullptr) {
					NodoArbol^ temp = raizActual->Izquierda;
					delete raizActual;
					return temp;
				}

				// Nodo con dos hijos, encontrar el sucesor in-order (mínimo en el subárbol derecho)
				NodoArbol^ temp = EncuentraMinimo(raizActual->Derecha);

				// Copiar el contenido del sucesor al nodo actual
				raizActual->Valor = temp->Valor;

				// Eliminar el sucesor
				raizActual->Derecha = EliminarRec(raizActual->Derecha, temp->Valor);
			}

			return raizActual;
		}

		NodoArbol^ EncuentraMinimo(NodoArbol^ raizActual) {
			while (raizActual->Izquierda != nullptr) {
				raizActual = raizActual->Izquierda;
			}
			return raizActual;
		}
	};

	/// <summary>
	/// Resumen de FormArbol
	/// </summary>
	public ref class FormArbol : public System::Windows::Forms::Form
	{
	private:
		ArbolBinario^ arbol; // Declaración de la variable arbol

	public:
		FormArbol(void)
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
		~FormArbol()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnInsertar;
	private: System::Windows::Forms::TextBox^ txtValor;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnMostrar;
	private: System::Windows::Forms::TreeView^ treeViewArbol;
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
			this->btnInsertar = (gcnew System::Windows::Forms::Button());
			this->txtValor = (gcnew System::Windows::Forms::TextBox());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnMostrar = (gcnew System::Windows::Forms::Button());
			this->treeViewArbol = (gcnew System::Windows::Forms::TreeView());
			this->SuspendLayout();
			// 
			// btnInsertar
			// 
			this->btnInsertar->Location = System::Drawing::Point(41, 55);
			this->btnInsertar->Name = L"btnInsertar";
			this->btnInsertar->Size = System::Drawing::Size(75, 23);
			this->btnInsertar->TabIndex = 0;
			this->btnInsertar->Text = L"nsertar";
			this->btnInsertar->UseVisualStyleBackColor = true;
			this->btnInsertar->Click += gcnew System::EventHandler(this, &FormArbol::btnInsertar_Click);
			// 
			// txtValor
			// 
			this->txtValor->Location = System::Drawing::Point(145, 55);
			this->txtValor->Name = L"txtValor";
			this->txtValor->Size = System::Drawing::Size(100, 20);
			this->txtValor->TabIndex = 1;
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(41, 98);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(75, 23);
			this->btnEliminar->TabIndex = 2;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormArbol::btnEliminar_Click);
			// 
			// btnMostrar
			// 
			this->btnMostrar->Location = System::Drawing::Point(271, 55);
			this->btnMostrar->Name = L"btnMostrar";
			this->btnMostrar->Size = System::Drawing::Size(75, 33);
			this->btnMostrar->TabIndex = 3;
			this->btnMostrar->Text = L"mostrar";
			this->btnMostrar->UseVisualStyleBackColor = true;
			this->btnMostrar->Click += gcnew System::EventHandler(this, &FormArbol::btnMostrar_Click);
			// 
			// treeViewArbol
			// 
			this->treeViewArbol->Location = System::Drawing::Point(117, 142);
			this->treeViewArbol->Name = L"treeViewArbol";
			this->treeViewArbol->Size = System::Drawing::Size(277, 145);
			this->treeViewArbol->TabIndex = 4;
			// 
			// FormArbol
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(552, 299);
			this->Controls->Add(this->treeViewArbol);
			this->Controls->Add(this->btnMostrar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->txtValor);
			this->Controls->Add(this->btnInsertar);
			this->Name = L"FormArbol";
			this->Text = L"FormArbol";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private:
		System::Void btnInsertar_Click(System::Object^ sender, System::EventArgs^ e) {
			int valor;
			if (Int32::TryParse(txtValor->Text, valor)) {
				arbol->Insertar(valor);
				arbol->MostrarEnTreeView(treeViewArbol);
			}
			else {
				MessageBox::Show("Ingrese un valor válido.");
			}
		}

		System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
			int valor;
			if (Int32::TryParse(txtValor->Text, valor)) {
				arbol->Eliminar(valor);
				arbol->MostrarEnTreeView(treeViewArbol);
			}
			else {
				MessageBox::Show("Ingrese un valor válido.");
			}
		}

		System::Void btnMostrar_Click(System::Object^ sender, System::EventArgs^ e) {
			arbol->MostrarEnTreeView(treeViewArbol);
		}
};
}
