using System;
using Model.Interfaces;
using System.Runtime.Serialization;

namespace Model
{
	/// <summary>
	/// Класс определяет <see cref="Width"/> и <see cref="Length"/> прямоугольника,
	/// считает <see cref="Surface"/> и <see cref="Perimeter"/>
	/// </summary>
	[DataContract]
	public class Rectangle : IFigure
	{
		/// <summary>
		/// Поле для площади прямоугольника
		/// </summary>
		private Lazy<double> _surface;

		/// <summary>
		/// Свойство для площади прямоугольника
		/// </summary>
		public double Surface => _surface.Value;

		/// <summary>
		/// Поле для периметра прямоугольника
		/// </summary>
		private Lazy<double> _perimeter;

		/// <summary>
		/// Свойство для периметра прямоугольника
		/// </summary>
		public double Perimeter => _perimeter.Value;

		/// <summary>
		/// Поле для ширины прямоугольника
		/// </summary>
		private double _width;

		/// <summary>
		/// Свойство для ширины прямоугольника
		/// </summary>
		[DataMember]
		public double Width
		{
			get => _width;
			set
			{
				ValueValidation.IsPositive(value, nameof(Width));
				_width = value;
				CalculationInit();
			}

		}
		/// <summary>
		/// Поле для длины прямоугольника
		/// </summary>
		private double _length;

		/// <summary>
		/// Свойство для длины прямоугольника
		/// </summary>
		[DataMember]
		public double Length
		{
			get => _length;
			set
			{
				ValueValidation.IsPositive(value, nameof(Length));
				_length = value;
				CalculationInit();
			}
		}

		/// <summary>
		/// Если поле <see cref="_surface"/> или <see cref="_perimeter"/>
		/// равны null, они инициализуются формулами для рассчета
		/// площади и периметра
		/// </summary>
		private void CalculationInit()
		{
			if (_surface != null && _perimeter != null) return;

			_surface = new Lazy<double>(() => Width * Length);
			_perimeter = new Lazy<double>(() => 2 * Width + 2 * Length);
		}

		/// <summary>
		/// Описание фигуры
		/// </summary>
		public string FigureDescription
		{
			get
			{
				const int valueAlignment = 4;
				return  $"Прямоугольник, ширина: {Width}," +
							$" длина: {Length}," +
							$" площадь: {Surface,valueAlignment:F3}," +
							$" периметр: {Perimeter,valueAlignment:F3}";
			}
		}

		/// <summary>
		/// Конструктор для класса <see cref="Rectangle"/>
		/// необходим для работы XML сериализации
		/// </summary>
		public Rectangle()
		{}
		
	}
}
