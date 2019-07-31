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

		//TODO: Опечатка
		/// <summary>
		/// Длина
		/// </summary>
		public double Lengh { get; }

		//TODO: XML
		public Rectangle()	{}

		//TODO: XML
		public Rectangle(double width, double length)
		{
			if (width <= 0 || length <= 0)
			{
				//TODO: Сообщение некорректно, т.к. значение может и не вводиться.
				throw new ArgumentException("Введенное значение меньше или равно 0");
			}

			Width = width;
			Lengh = length;

			Surface = width * length;
			Perimeter = 2 * width + 2 * length;
		}

		//TODO: Правильнее сделать свойством
		/// <summary>
		/// Вывод информации о фигуре
		/// </summary>
		public void GetDescription()
		{
			//TODO: Переделай в интерполяционную строку - лучше будет смотреться
			Console.WriteLine("Прямоугольник, ширина: {0}, длина: {1}, площадь: {2:0.00}, периметр: {3:0.00}",
				Width, Lengh, Surface, Perimeter);
		}
	}
}
