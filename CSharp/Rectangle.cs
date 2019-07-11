using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;

namespace Model
{
	public class Rectangle : IFigure
	{
		/// <summary>
		/// Площадь фигуры
		/// </summary>
		public double Surface { get; }

		/// <summary>
		/// Периметр фигуры
		/// </summary>
		public double Perimeter { get; }

		/// <summary>
		/// Ширина
		/// </summary>
		public double Width { get; }

		/// <summary>
		/// Длина
		/// </summary>
		public double Lengh { get; }

		public Rectangle(double width, double length)
		{
			Width = width;
			Lengh = length;

			Surface = width * length;
			Perimeter = 2 * width + 2 * length;
		}

		/// <summary>
		/// Вывод информации о фигуре
		/// </summary>
		public void GetDescription()
		{
			Console.WriteLine("Прямоугольник, ширина: {0}, длина: {1}, площадь: {2:0.00}, периметр: {3:0.00}",
				Width, Lengh, Surface, Perimeter);
		}
	}
}
