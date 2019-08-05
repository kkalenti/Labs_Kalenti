using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
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
		/// Длинна
		/// </summary>
		public double Length { get; }

		/// <summary>
		/// Описание фигуры
		/// </summary>
		public string Description { get; }

		//TODO: XML
		public Rectangle()	{}

		//TODO: XML
		public Rectangle(double width, double length)
		{
			const int valueAlignment = 4;
			if (width <= 0 || length <= 0)
			{
				//TODO: Сообщение некорректно, т.к. значение может и не вводиться. done
				throw new ArgumentException();
			}

			Width = width;
			Length = length;

			Surface = width * length;
			Perimeter = 2 * width + 2 * length;
			Description = $"Прямоугольник, ширина: {Width}, длина: {Length}," +
			              $" площадь: {Surface,valueAlignment:F3}, периметр: {Perimeter,valueAlignment:F3}";
		}

		//TODO: Правильнее сделать свойством done
		/// <summary>
		/// Вывод информации о фигуре
		/// </summary>
		public void ShowDescription()
		{
			//TODO: Переделай в интерполяционную строку - лучше будет смотреться done
			Console.WriteLine(Description);
		}
	}
}
