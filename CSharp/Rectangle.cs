using System;
//TODO: using done
using Model.Interfaces;
using System.Runtime.Serialization;

namespace Model
{
	//TODO: XML done
	/// <summary>
	/// Класс определяет <see cref="Width"/> и <see cref="Length"/> прямоугольника,
	/// считает <see cref="Surface"/> и <see cref="Perimeter"/>
	/// </summary>
	[DataContract]
	public class Rectangle : IFigure
	{
		// TODO: nameof done
		/// <summary>
		/// Имя фигуры
		/// </summary>
		public string Name => nameof(Rectangle);

		//TODO: XML done
		/// <summary>
		/// Поле для площади прямоугольника
		/// </summary>
		private Lazy<double> _surface;

		/// <summary>
		/// Свойство для площади прямоугольника
		/// </summary>
		public double Surface => _surface.Value;

		//TODO: XML done
		/// <summary>
		/// Поле для периметра прямоугольника
		/// </summary>
		private Lazy<double> _perimeter;

		/// <summary>
		/// Свойство для периметра прямоугольника
		/// </summary>
		public double Perimeter => _perimeter.Value;

		//TODO: XML done
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
				// TODO: nameof done
				ValueValidation.IsPositive(value, nameof(Width));
				_width = value;
				CalculationInit();
			}

		}

		//TODO: XML done
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
				// TODO: nameof done
				ValueValidation.IsPositive(value, nameof(Length));
				_length = value;
				CalculationInit();
			}
		}

		//TODO: Название метода не отражает назначения done
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
		/// // TODO: RSDN done
		public string Description
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

		//TODO: XML <see cref... done
		/// <summary>
		/// Конструктор для класса <see cref="Rectangle"/>
		/// необходим для работы XML сериализации
		/// </summary>
		public Rectangle()
		{}
		
	}
}
