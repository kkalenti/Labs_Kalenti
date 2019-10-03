using System;
//TODO: using done 
using Model;
using NUnit.Framework;

namespace UnitTests.Model
{
	/// <summary>
	/// Набор тестов класса Circle
	/// </summary>
	[TestFixture]
	internal class CircleTest
	{
		[Test]
		[TestCase(1, TestName = "Тестирование конструктора при присваивании 1")]
		[TestCase(4, TestName = "Тестирование конструктора при присваивании 4")]
		[TestCase(double.MaxValue, TestName = 
			"Тестирование конструктора при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, TestName = 
			"Тестирование конструктора при присваивании Double.MaxValue - 1")]
		public void ConstructorPositiveTest(double radius)
		{
			// arrange
			new Circle()
			{
				Radius = radius
			};
			// act

			// assert

		}


		[Test]
		[TestCase(1, TestName = "Тестирование радиуса при присваивании 1")]
		[TestCase(4, TestName = "Тестирование радиуса при присваивании 4")]
		[TestCase(double.MaxValue,TestName =
			"Тестирование радиуса при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, TestName =
			"Тестирование радиуса при присваивании Double.MaxValue - 1")]
		public void RadiusTest(double radius)
		{
			// arrange
			var circle = new Circle()
			{
				Radius = radius
			};

			// act
			var localRadius = circle.Radius;

			// assert
			Assert.AreEqual(radius, circle.Radius);
		}

		[Test]
		[TestCase(1, TestName = "Тестирование описания круга при присваивании 1")]
		[TestCase(4, TestName = "Тестирование описания круга при присваивании 4")]
		[TestCase(double.MaxValue, TestName =
			"Тестирование описания круга при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, TestName =
			"Тестирование описания круга при присваивании Double.MaxValue - 1")]
		public void DescriptionTest(double radius)
		{
			// arrange
			var circle = new Circle()
			{
				Radius = radius
			};

			// act
			var surface = 2 * Math.PI * radius;
			var perimeter = Math.PI * radius * radius;

			// assert
			Assert.AreEqual($"Круг, радиус: {radius}," + 
			                $" площадь: {surface,4:F3}," +
			                $" периметр: {perimeter,4:F3}",
				circle.Description);
		}

		[Test]
		[TestCase(1, TestName = "Тестирование площади при присваивании 1")]
		[TestCase(4, TestName = "Тестирование площади при присваивании 4")]
		[TestCase(double.MaxValue, TestName =
			"Тестирование площади при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, TestName =
			"Тестирование площади при присваивании Double.MaxValue - 1")]
		public void SurfaceTest(double radius)
		{
			// arrange
			var circle = new Circle()
			{
				Radius = radius
			};

			// act
			var surface = 2 * Math.PI * radius;

			// assert
			Assert.AreEqual(surface,circle.Surface);
		}

		[Test]
		[TestCase(1, TestName = "Тестирование периметра при присваивании 1")]
		[TestCase(4, TestName = "Тестирование периметра при присваивании 4")]
		[TestCase(double.MaxValue, TestName =
			"Тестирование периметра при присваивании Double.MaxValue")]
		[TestCase(double.MaxValue - 1, TestName =
			"Тестирование периметра при присваивании Double.MaxValue - 1")]
		public void PerimeterTest(double radius)
		{
			// arrange
			var circle = new Circle()
			{
				Radius = radius
			};

			// act
			var perimeter = Math.PI * radius * radius;

			// assert
			Assert.AreEqual(perimeter, circle.Perimeter);
		}

		[Test]
		[TestCase(TestName = "Тестирование возврата имени класса")]
		public void NameTest()
		{
			// arrange
			var circle = new Circle();

			// act

			// assert
			Assert.AreEqual("Circle", circle.Name);
		}

		[Test]
		[TestCase(-1, TestName = "Тестирование конструктора при присваивании -1")]
		[TestCase(double.MinValue, TestName =
			"Тестирование конструктора при присваивании Double.MinValue")]
		[TestCase(double.NaN, TestName = 
			"Тестирование конструктора при присваивании Double.NaN")]
		[TestCase(double.NegativeInfinity, TestName = 
			"Тестирование конструктора при присваивании Double.NegativeInfinity")]
		[TestCase(double.PositiveInfinity, TestName = 
			"Тестирование конструктора при присваивании Double.PositiveInfinity")]
		public void ConstructorNegativeTest(double radius)
		{
			Assert.That(() => new Circle()
				{
					Radius = radius
				},
				Throws.TypeOf<ArgumentException>());
		}
	}
}
