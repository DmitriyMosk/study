#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ выборЦветаФормыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ красныйToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ жёлтыйToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ синийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ораньжевыйToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ отменаЦветаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ работаСМатрицейToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ формированиеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ обработкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сведенияОРазработчикеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ заданиеПоОбработкеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выборЦветаФормыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->красныйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->жёлтыйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->синийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ораньжевыйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->отменаЦветаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->работаСМатрицейToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->формированиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обработкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сведенияОРазработчикеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->заданиеПоОбработкеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->выборЦветаФормыToolStripMenuItem,
					this->работаСМатрицейToolStripMenuItem, this->оПрограммеToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1072, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выборЦветаФормыToolStripMenuItem
			// 
			this->выборЦветаФормыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->красныйToolStripMenuItem,
					this->жёлтыйToolStripMenuItem, this->синийToolStripMenuItem, this->ораньжевыйToolStripMenuItem, this->отменаЦветаToolStripMenuItem
			});
			this->выборЦветаФормыToolStripMenuItem->Name = L"выборЦветаФормыToolStripMenuItem";
			this->выборЦветаФормыToolStripMenuItem->Size = System::Drawing::Size(167, 24);
			this->выборЦветаФормыToolStripMenuItem->Text = L"Выбор цвета формы";
			this->выборЦветаФормыToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выборЦветаФормыToolStripMenuItem_Click);
			// 
			// красныйToolStripMenuItem
			// 
			this->красныйToolStripMenuItem->Name = L"красныйToolStripMenuItem";
			this->красныйToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->красныйToolStripMenuItem->Text = L"Красный";
			this->красныйToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::красныйToolStripMenuItem_Click);
			// 
			// жёлтыйToolStripMenuItem
			// 
			this->жёлтыйToolStripMenuItem->Name = L"жёлтыйToolStripMenuItem";
			this->жёлтыйToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->жёлтыйToolStripMenuItem->Text = L"Жёлтый";
			this->жёлтыйToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::жёлтыйToolStripMenuItem_Click);
			// 
			// синийToolStripMenuItem
			// 
			this->синийToolStripMenuItem->Name = L"синийToolStripMenuItem";
			this->синийToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->синийToolStripMenuItem->Text = L"Синий";
			this->синийToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::синийToolStripMenuItem_Click);
			// 
			// ораньжевыйToolStripMenuItem
			// 
			this->ораньжевыйToolStripMenuItem->Name = L"ораньжевыйToolStripMenuItem";
			this->ораньжевыйToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->ораньжевыйToolStripMenuItem->Text = L"Оранжевый";
			this->ораньжевыйToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::оранжевыйToolStripMenuItem_Click);
			// 
			// отменаЦветаToolStripMenuItem
			// 
			this->отменаЦветаToolStripMenuItem->Name = L"отменаЦветаToolStripMenuItem";
			this->отменаЦветаToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->отменаЦветаToolStripMenuItem->Text = L"Отмена цвета";
			this->отменаЦветаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::отменаЦветаToolStripMenuItem_Click);
			// 
			// работаСМатрицейToolStripMenuItem
			// 
			this->работаСМатрицейToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->формированиеToolStripMenuItem,
					this->обработкаToolStripMenuItem
			});
			this->работаСМатрицейToolStripMenuItem->Name = L"работаСМатрицейToolStripMenuItem";
			this->работаСМатрицейToolStripMenuItem->Size = System::Drawing::Size(155, 24);
			this->работаСМатрицейToolStripMenuItem->Text = L"Работа с матрицей";
			this->работаСМатрицейToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::работаСМатрицейToolStripMenuItem_Click);
			// 
			// формированиеToolStripMenuItem
			// 
			this->формированиеToolStripMenuItem->Name = L"формированиеToolStripMenuItem";
			this->формированиеToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			this->формированиеToolStripMenuItem->Text = L"Формирование";
			this->формированиеToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::формированиеToolStripMenuItem_Click);
			// 
			// обработкаToolStripMenuItem
			// 
			this->обработкаToolStripMenuItem->Name = L"обработкаToolStripMenuItem";
			this->обработкаToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			this->обработкаToolStripMenuItem->Text = L"Обработка";
			this->обработкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::обработкаToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->сведенияОРазработчикеToolStripMenuItem,
					this->заданиеПоОбработкеToolStripMenuItem
			});
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(118, 24);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::оПрограммеToolStripMenuItem_Click);
			// 
			// сведенияОРазработчикеToolStripMenuItem
			// 
			this->сведенияОРазработчикеToolStripMenuItem->Name = L"сведенияОРазработчикеToolStripMenuItem";
			this->сведенияОРазработчикеToolStripMenuItem->Size = System::Drawing::Size(273, 26);
			this->сведенияОРазработчикеToolStripMenuItem->Text = L"Сведения о разработчике";
			this->сведенияОРазработчикеToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::сведенияОРазработчикеToolStripMenuItem_Click);
			// 
			// заданиеПоОбработкеToolStripMenuItem
			// 
			this->заданиеПоОбработкеToolStripMenuItem->Name = L"заданиеПоОбработкеToolStripMenuItem";
			this->заданиеПоОбработкеToolStripMenuItem->Size = System::Drawing::Size(273, 26);
			this->заданиеПоОбработкеToolStripMenuItem->Text = L"Задание по обработке";
			this->заданиеПоОбработкеToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::заданиеПоОбработкеToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(67, 24);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(426, 261);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Результат обработки матрицы";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1072, 482);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void выборЦветаФормыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {} 
	private: System::Void красныйToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->BackColor = Color::Red; 
	}
	private: System::Void жёлтыйToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->BackColor = Color::Yellow;
	}
	private: System::Void синийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->BackColor = Color::Blue;
	}
	private: System::Void оранжевыйToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->BackColor = Color::Orange; 
	}
	private: System::Void отменаЦветаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->BackColor = Color::White; 
	}

	private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {} 
	private: System::Void сведенияОРазработчикеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::String^ s = gcnew String("ФИО: Московских Дмитрий Петрович\nГруппа: ИА-232");

		MessageBox::Show(s, " Сведения о разработчике");
	}
	private: System::Void заданиеПоОбработкеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::String^ s = gcnew String("Написать программу\n  - сформировать матрицу А(NхN)\n  - найти в матрице количество четных чисел над главной диагональю матрицы\n  -найти значения максимального на главной диагонали и минимального элемента матрицы на побочной диагонали.");

		MessageBox::Show(s, " Задание по обработке");
	}

	private: System::Void работаСМатрицейToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void формированиеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		int i, j;
		
		System::String ^ s = gcnew String("");
		form(A);//вызов функции Form()
		//Вывод матрицы в окно MessageBox
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
				s = s + System::Convert::ToString(A[i][j]) + "\t";
			s = s + "\r\n";
		}
		MessageBox::Show(s, " Матрица");
	}
	private: System::Void обработкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		int max, min;
		max = Maximum(A);//вызов функции Maximum()
		min = Minimum(A);
		label1->Text = "Максимум на главной диагонали=" + System::Convert::ToString(max) + "\n" + "Минимум на побочной=" + System::Convert::ToString(min);
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) { }
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) { } 

	private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
};
}

