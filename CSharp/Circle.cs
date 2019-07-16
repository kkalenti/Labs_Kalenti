using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;

namespace Model
{	
	[Serializable]
	/// <summary>
	/// Класс для кругов
	/// </summary>
	public class Circle : IFigure
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
		/// Радиус фигуры
		/// </summary>
		public double Radius { get; }
		
		public Circle() { }

		public  Circle(double radius)
		{
			Radius = radius;
			Surface = 2 * Math.PI * radius;
			Perimeter = Math.PI * Radius * Radius;
		}

		/// <summary>
		/// Вывод информации о фигуре
		/// </summary>
		public void GetDescription()
		{
			Console.WriteLine("Круг, радиус: {0}, площадь: {1:0.00}, периметр: {2:0.00}",
				Radius, Surface, Perimeter);
		}
	}
}