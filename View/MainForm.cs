using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model;
using Model.Interfaces;
using System.Windows.Forms;

namespace View
{
	public partial class MainForm : Form
	{
		public List<IFigure> figures = new List<IFigure>();

		public MainForm()
		{
			InitializeComponent();
		}

		private void AddButton_Click(object sender, EventArgs e)
		{
			AddingForm adding = new AddingForm(this);
			adding.Show();
		}

		private void RemoveButton_Click(object sender, EventArgs e)
		{
			foreach (DataGridViewRow row in FigureGrid.SelectedRows)
			{
				figures.RemoveAt(row.Index);
				FigureGrid.Rows.Remove(row);
			}
		}

		/// <summary>
		/// Добавление круга в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		public void CircleToList(double radius)
		{
			IFigure circle = new Model.Circle(radius);
			figures.Add(circle);
			FigureGrid.Rows.Add("Circle", circle.Surface, circle.Perimeter);
		}

		/// <summary>
		/// Добавление прямугольника в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		public void RectangleToList(double width, double length)
		{
			IFigure rectangle = new Model.Rectangle(width, length);
			figures.Add(rectangle);
			FigureGrid.Rows.Add("Rectangle", rectangle.Surface, rectangle.Perimeter);
		}

		//TODO: че сделать чтобы она не отображалась?
#if DEBUG
		private void RandomObjectButton_Click(object sender, EventArgs e)
		{
			Random rand = new Random();
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

		private void FindObjectButton_Click(object sender, EventArgs e)
		{
			FindingForm finding = new FindingForm(this);
			finding.Show();
		}
	}
}
