using System;
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
	class CircleTest
	{
		[Test]
		[TestCase(1, TestName = "Тестирование конструктора при присваивании 1")]
		[TestCase(4, TestName = "Тестирование конструктора при присваивании 4")]
		[TestCase(Double.MaxValue, TestName = "Тестирование конструктора при присваивании Double.MaxValue")]
		[TestCase(Double.MaxValue - 1, TestName = "Тестирование конструктора при присваивании Double.MaxValue - 1")]
		public void ConstructorPositiveTest(double radius)
		{
			new Circle(radius);
		}

		[Test]
		[TestCase(-1, TestName = "Тестирование конструктора при присваивании -1")]
		[TestCase(Double.MinValue, TestName = "Тестирование конструктора при присваивании Double.MinValue")]
		[TestCase(Double.NaN, TestName = "Тестирование конструктора при присваивании Double.NaN")]
		[TestCase(Double.NegativeInfinity, TestName = "Тестирование конструктора при присваивании Double.NegativeInfinity")]
		[TestCase(Double.PositiveInfinity, TestName = "Тестирование конструктора при присваивании Double.PositiveInfinity")]
		public void ConstructorNegativeTest(double radius)
		{
			Assert.That(() => new Circle(radius),
				Throws.TypeOf<ArgumentException>());
		}
	}
}
