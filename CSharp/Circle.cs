using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using System.Xml.Serialization;

//TODO: Некорректный namespace - посмотри настройки проекта
namespace Model
{	
	//TODO: Аттрибуты должны быть после xml
	[Serializable]
	/// <summary>
	/// Класс для кругов
	/// </summary>
	public class Circle : IFigure
	{
		//TODO: Аттрибуты должны быть после xml
		[XmlAttribute]
		/// <summary>
		/// Площадь фигуры
		/// </summary>
		public double Surface { get; }

		//TODO: Аттрибуты должны быть после xml
		[XmlAttribute]
		/// <summary>
		/// Периметр фигуры
		/// </summary>
		public double Perimeter { get; }

		//TODO: Аттрибуты должны быть после xml
		[XmlAttribute]
		/// <summary>
		/// Радиус фигуры
		/// </summary>
		public double Radius { get; }

		/// <summary>
		/// Описание фигуры
		/// </summary>
		public string Description { get; }

		/// <summary>
		/// Конструктор по-умолчанию для работы XML сериализации
		/// </summary>
		public Circle() { }

		//TODO: я бы писал подругому Конструктор класса <see cref=Circle>
		/// <summary>
		/// TODO: некорректный комментарий
		/// Конструктор для объектов "Круг"
		/// </summary>
		/// <param name="radius">Радиус круга</param>
		public Circle(double radius)
		{
			const int valueAlignment = 4;
			if (radius <= 0 || double.IsNaN(radius) || double.IsInfinity(radius))
			{
				//TODO: Как будешь определять - что пошло не так?
				throw new ArgumentException();
			}

			Radius = radius;
			//TODO: Не совсем удачная с точки зрения масштабирования модель, т.к. есть 
			//TODO: вероятность, что я не вызову никогда эти свойства, а время на их расчёт
			//TODO: уже потратится. А если их будет 100000000000 (много?)
			Surface = 2 * Math.PI * radius;
			Perimeter = Math.PI * Radius * Radius;
			//TODO: Длинная строка
			Description = $"Круг, радиус: {Radius}, площадь: {Surface,valueAlignment:F3}," +
			              $" периметр: {Perimeter,valueAlignment:F3}";
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