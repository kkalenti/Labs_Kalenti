using System;
using Model;
using NUnit.Framework;

namespace UnitTests.Model
{
	[TestFixture]
	class RectangleTest
	{
		[Test]
		[TestCase(1, 1, TestName = "Тестирование конструктора при присваивании 1")]
		[TestCase(4, 4, TestName = "Тестирование конструктора при присваивании 4")]
		[TestCase(double.MaxValue, double.MaxValue, 
			TestName = "Тестирование конструктора при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, double.MaxValue - 1, 
			TestName = "Тестирование конструктора при присваивании Double.MaxValue - 1")]
		public void RectanglePositiveTest(double width, double length)
		{
			// arrange
			// act
			new Rectangle()
			{
				Width = width,
				Length = length
			};
			// assert
		}

		[Test]
		[TestCase(1, 1, TestName = "Тестирование длины при присваивании 1")]
		[TestCase(4, 4, TestName = "Тестирование длины при присваивании 4")]
		[TestCase(double.MaxValue, double.MaxValue,
			TestName = "Тестирование длины при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, double.MaxValue - 1,
			TestName = "Тестирование длины при присваивании Double.MaxValue - 1")]
		public void LengthTest(double width, double length)
		{
			// arrange
			var rectangle = new Rectangle()
			{
				Width = width,
				Length = length
			};

			// act

			// assert
			Assert.AreEqual(length,rectangle.Length);
		}

		[Test]
		[TestCase(1, 1, TestName = "Тестирование ширины при присваивании 1")]
		[TestCase(4, 4, TestName = "Тестирование ширины при присваивании 4")]
		[TestCase(double.MaxValue, double.MaxValue,
			TestName = "Тестирование ширины при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, double.MaxValue - 1,
			TestName = "Тестирование ширины при присваивании Double.MaxValue - 1")]
		public void WidthTest(double width, double length)
		{
			// arrange
			var rectangle = new Rectangle()
			{
				Width = width,
				Length = length
			};

			// act

			// assert
			Assert.AreEqual(width, rectangle.Width);
		}

		[Test]
		[TestCase(1, 1, TestName = "Тестирование описания прямоугольника при присваивании 1")]
		[TestCase(4, 4, TestName = "Тестирование описания прямоугольника при присваивании 4")]
		[TestCase(double.MaxValue, double.MaxValue,
			TestName = "Тестирование описания прямоугольника при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, double.MaxValue - 1,
			TestName = "Тестирование описания прямоугольника при присваивании Double.MaxValue - 1")]
		public void DescriptionTest(double width, double length)
		{
			// arrange
			var rectangle = new Rectangle()
			{
				Width = width,
				Length = length
			};

			// act
			var surface = width * length;
			var perimeter = 2 * width + 2 * length;

			// assert
			Assert.AreEqual($"Прямоугольник, ширина: { width}," +
				$" длина: {length}," +
				$" площадь: {surface,4:F3}," +
				$" периметр: {perimeter,4:F3}",
				rectangle.FigureDescription);
		}

		[Test]
		[TestCase(1, 1, TestName = "Тестирование площади при присваивании 1")]
		[TestCase(4, 4, TestName = "Тестирование площади при присваивании 4")]
		[TestCase(double.MaxValue, double.MaxValue,
			TestName = "Тестирование площади при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, double.MaxValue - 1,
			TestName = "Тестирование площади при присваивании Double.MaxValue - 1")]
		public void SurfaceTest(double width, double length)
		{
			// arrange
			var rectangle = new Rectangle()
			{
				Width = width,
				Length = length
			};

			// act
			var surface = width * length;

			// assert
			Assert.AreEqual(surface,rectangle.Surface);
		}

		[Test]
		[TestCase(1, 1, TestName = "Тестирование периметра при присваивании 1")]
		[TestCase(4, 4, TestName = "Тестирование периметра при присваивании 4")]
		[TestCase(double.MaxValue, double.MaxValue,
			TestName = "Тестирование периметра при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, double.MaxValue - 1,
			TestName = "Тестирование периметра при присваивании Double.MaxValue - 1")]
		public void PerimeterTest(double width, double length)
		{
			// arrange
			var rectangle = new Rectangle()
			{
				Width = width,
				Length = length
			};

			// act
			var perimeter = 2 * width + 2 * length;

			// assert
			Assert.AreEqual(perimeter, rectangle.Perimeter);
		}

		[Test]
		[TestCase(TestName = "Тестирование возврата имени класса")]
		public void NameTest()
		{
			// arrange
			var rectangle = new Rectangle();

			// act

			// assert
			Assert.AreEqual("Rectangle",nameof(Rectangle));
		}

		[Test]
		[TestCase(-1, -1,
			TestName = "Тестирование конструктора при присваивании -1")]
		[TestCase(Double.MinValue, Double.MinValue,
			TestName = "Тестирование конструктора при присваивании Double.MinValue")]
		[TestCase(Double.NaN, Double.NaN, TestName =
			"Тестирование конструктора при присваивании Double.NaN")]
		[TestCase(Double.NegativeInfinity, Double.NegativeInfinity,
			TestName = "Тестирование конструктора при присваивании Double.NegativeInfinity")]
		[TestCase(Double.PositiveInfinity, Double.PositiveInfinity,
			TestName = "Тестирование конструктора при присваивании Double.PositiveInfinity")]
		public void RectangleNegativeTest(double width, double length)
		{
			Assert.That(() => new Rectangle()
				{
					Width = width,
					Length = length
				}, 
				Throws.TypeOf<ArgumentException>());
		}
	}
}
