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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	protected:

	private:
		int CurrentColor = 1; // цвет фигуры
		int CurrentPattern = 1; // узор фигуры
	private: System::Windows::Forms::Button^ button3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(181, 250);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Узор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(27, 250);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 53);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Фигура";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(333, 250);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 53);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Текст";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(441, 330);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}

	#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) // Узоры
	{
		Graphics^ gfx = CreateGraphics();
		System::Drawing::Drawing2D::HatchBrush^ Brsh = gcnew
			System::Drawing::Drawing2D::HatchBrush
			(System::Drawing::Drawing2D::HatchStyle::Cross,
				Color::Aqua, Color::Red);

		Point x1 = Point(200, 80);
		Point x2 = Point(150, 80);
		Point x3 = Point(150, 120);
		array <Point>^ xx = { x1,x2,x3 };

		gfx->FillPolygon(Brsh, xx);

		Graphics^ gfx_quadro = CreateGraphics();
		System::Drawing::Drawing2D::HatchBrush^ Brsh_quadro = gcnew
			System::Drawing::Drawing2D::HatchBrush
			(System::Drawing::Drawing2D::HatchStyle::Cross,
				Color::Aqua, Color::Red);

		x1 = Point(200, 80);
		x2 = Point(200, 50);
		x3 = Point(230, 50);
		Point x4 = Point(230, 80);
		array <Point>^ xx_quadro = { x1,x2,x3,x4 };


		gfx_quadro->FillPolygon(Brsh_quadro, xx_quadro);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) // Отрисовка фигуры
	{
		System::Drawing::Pen^ P = gcnew System::Drawing::Pen(Color::Black);
		Graphics^ gfx = CreateGraphics();
		Point x1 = Point(200, 80);
		Point x2 = Point(150, 80);
		Point x3 = Point(150, 120);
		array <Point>^ xx = { x1,x2,x3 };
		gfx->DrawPolygon(Pens::Red, xx);

		Graphics^ gfx_cuadro = CreateGraphics();
		x1 = Point(200, 80);
		x2 = Point(200, 50);
		x3 = Point(230, 50);
		Point x4 = Point(230, 80);
		array <Point>^ xx_quadro = { x1,x2,x3,x4 };
		gfx_cuadro->DrawPolygon(Pens::Red, xx_quadro);
	}

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) 
	{
		System::Drawing::Drawing2D::HatchBrush^ Brsh = gcnew
			System::Drawing::Drawing2D::HatchBrush
			(System::Drawing::Drawing2D::HatchStyle::Cross,
				Color::Aqua, Color::Red);

		System::Drawing::Font^ fnt = gcnew System::Drawing::Font("Times New Roman", 24);

		Graphics^ gfx_text = CreateGraphics();

		gfx_text->DrawString("Текст", fnt, Brsh, Point(10, 10));
	}
};
}
