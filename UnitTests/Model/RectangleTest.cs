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
	[TestFixture]
	class RectangleTest
	{
		[Test]
		[TestCase(1, 1, TestName = "Тестирование конструктора при присваивании 1")]
		[TestCase(4, 4, TestName = "Тестирование конструктора при присваивании 4")]
		[TestCase(Double.MaxValue, Double.MaxValue, TestName = "Тестирование конструктора при присваивании Double.MaxValue")]
		[TestCase(Double.MaxValue - 1, Double.MaxValue - 1, TestName = "Тестирование конструктора при присваивании Double.MaxValue - 1")]
		public void RectanglePositiveTest(double width, double length)
		{
			new Rectangle(width, length);
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
			Assert.That(() => new Rectangle(width, length), 
				Throws.TypeOf<ArgumentException>());
		}
	}
}
