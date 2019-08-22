using System;
//TODO: using
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using System.Xml.Serialization;
using System.Runtime.Serialization;

namespace Model
{
	//TODO: Комментарий не описывает назначение класса
	/// <summary>
	/// Класс для кругов
	/// </summary>
	[DataContract]
	public class Circle : IFigure
	{
		/// <summary>
		/// Имя фигуры
		/// </summary>
		/// TODO: nameof
		public string Name => "Circle";
		//TODO: XML
		private Lazy<double> _surface;
		/// <summary>
		/// Площадь фигуры
		/// </summary>
		public double Surface => _surface.Value;
		//TODO: XML
		private Lazy<double> _perimeter;
		/// <summary>
		/// Периметр фигуры
		/// </summary>
		public double Perimeter => _perimeter.Value;
		//TODO: XML
		private double _radius;

		/// <summary>
		/// Радиус фигуры
		/// </summary>
		[DataMember]
		public double Radius
		{
			get => _radius;
			set
			{
				// TODO: nameof
				ValueValidation.IsPositive(value, "Radius");
				_radius = value;
				//TODO: invert
				if (_surface == null || _perimeter == null)
				{
					_surface = new Lazy<double>(() => 2 * Math.PI * Radius);
					_perimeter = new Lazy<double>(() => Math.PI * Radius * Radius);
				}
			}
		}

		/// <summary>
		/// Описание фигуры
		/// </summary>
		/// TODO: RSDN
		public string Description {
			get
			{
				const int valueAlignment = 4;
				return $"Круг, радиус: {Radius}," +
				       $" площадь: {Surface,valueAlignment:F3}," +
				       $" периметр: {Perimeter,valueAlignment:F3}";
			}

		}

		//TODO: XML <see cref...
		/// <summary>
		/// Конструктор по-умолчанию для работы XML сериализации
		/// </summary>
		public Circle()
		{}

		//TODO: А этот конструктор нужен вообще, если есть возможность сразу инициализировать свойства?
		/// <summary>
		/// Конструктор класса <see cref="Circle"/>
		/// </summary>
		/// <param name="radius">Радиус круга</param>
		public Circle(double radius)
		{
			Radius = radius;
		}
	}
}