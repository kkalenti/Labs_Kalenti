using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
	public class Circle : IFigure
	{
		private double _radius;

		public double Angles { get; }
		public double Radius {
			get
			{
				return _radius;
			}
			set
			{
				if(value <= 0)
				{
					throw new ArgumentException("Введенное значение меньше или равно 0");
				}
				else
				{
					_radius = value;
				}
			}
		}

		public Circle(double radius)
		{
			_radius = radius;
		}

		public double CalculatePerimeter()
		{
			return 2 * Math.PI * _radius;
		}

		public double CalculateSurface()
		{
			return Math.PI * _radius * _radius;
		}
	}
}