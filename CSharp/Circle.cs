using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;

namespace Model
{	/// <summary>
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
		
		public  Circle(double radius)
		{
			Radius = radius;
			Surface = 2 * Math.PI * radius;
			Perimeter = Math.PI * Radius * Radius;
		}
	}
}