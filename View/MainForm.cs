﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using Model;
using Model.Interfaces;
using System.Windows.Forms;
using System.IO;

namespace View
{
	/// <summary>
	/// Основная форма
	/// </summary>
	public partial class MainForm : Form
	{
		/// <summary>
		/// Список фигур
		/// </summary>
		/// //TODO: RSDN done
		public List<IFigure> Figures = new List<IFigure>();

		/// <summary>
		/// Конструктор главной формы
		/// </summary>
		//TODO: XML done
		public MainForm()
		{
			InitializeComponent();
		}

		/// <summary>
		/// Обработка кнопки для открытия формы добавления фигуры
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void AddButton_Click(object sender, EventArgs e)
		{
			var adding = new AddingForm
			{
				Owner = this
			};
			adding.Show();
		}

		/// <summary>
		/// Обработка кнопки удаления выделенных строк
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RemoveButton_Click(object sender, EventArgs e)
		{
			foreach (DataGridViewRow row in FigureGrid.SelectedRows)
			{
				Figures.RemoveAt(row.Index);
				FigureGrid.Rows.Remove(row);
			}
		}

		/// <summary>
		/// Добавление круга в список
		/// </summary>
		/// <param name="radius"> Радиус фигуры </param>
		/// //TODO: XML done
		public void CircleToList(double radius)
		{
			IFigure circle = new Model.Circle(radius);
			Figures.Add(circle);
			FigureGrid.Rows.Add("Circle", circle.Surface, circle.Perimeter);
		}

		/// <summary>
		/// Добавление прямугольника в список
		/// </summary>
		/// <param name="width"> Ширина прямоугольника </param>
		/// <param name="length"> Длина прямоугольника </param>
		/// //TODO: XML done
		public void RectangleToList(double width, double length)
		{
			IFigure rectangle = new Model.Rectangle(width, length);
			Figures.Add(rectangle);
			FigureGrid.Rows.Add("Rectangle", rectangle.Surface, rectangle.Perimeter);
		}

#if DEBUG
		/// <summary>
		/// Генерация рандомной фигуры
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RandomObjectButton_Click(object sender, EventArgs e)
		{
			var rand = new Random();
			bool flag = rand.Next(0, 2) == 1;
			if(flag == true)
			{
				CircleToList(rand.Next(1, 20));
			}
			else
			{
				RectangleToList(rand.Next(1, 20), rand.Next(1, 20));
			}
		}
#endif

		/// <summary>
		/// Обработка кнопки для открытия формы поиска
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void FindObjectButton_Click(object sender, EventArgs e)
		{
			var finding = new FindingForm
			{
				Owner = this
			};
			finding.Show();
		}

		/// <summary>
		/// Обработка кнопки для сохранения данных
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SaveButton_Click(object sender, EventArgs e)
		{
			foreach (IFigure figure in Figures)
			{
				//TODO: Дубль done
				var writer = new XmlSerializer(figure.GetType());
				//TODO: Абсолютные пути, серьёзно? done
				using (var file = new FileStream("..\\..\\Xml\\figures.xml", FileMode.Append))
				{
					writer.Serialize(file, figure);
				}
			}
		}
	}
}
