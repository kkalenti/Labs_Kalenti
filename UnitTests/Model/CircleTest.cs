using System;
//TODO: using
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model;
using NUnit.Framework;
using NUnit.Framework.Internal;

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
			//TODO: triple A testing structure

			new Circle(radius);
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
			Assert.That(() => new Circle(radius),
				Throws.TypeOf<ArgumentException>());
		}
	}
}
