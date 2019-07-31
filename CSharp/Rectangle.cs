using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;

namespace Model
{
	[Serializable]
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
		public double Length { get; }

		public Rectangle()	{}

		public Rectangle(double width, double length)
		{
			if (width <= 0 || Double.IsNaN(width) || Double.IsInfinity(width)
				|| length <= 0 || Double.IsNaN(length) || Double.IsInfinity(length))
			{
				throw new ArgumentException("Введенное значение меньше или равно 0");
			}

			Width = width;
			Length = length;

			Surface = width * length;
			Perimeter = 2 * width + 2 * length;
		}

		/// <summary>
		/// Вывод информации о фигуре
		/// </summary>
		public void GetDescription()
		{
			Console.WriteLine("Прямоугольник, ширина: {0}, длина: {1}, площадь: {2:0.00}, периметр: {3:0.00}",
				Width, Length, Surface, Perimeter);
		}
	}
}
