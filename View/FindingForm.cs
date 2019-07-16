using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using System.Windows.Forms;

namespace View
{
	public partial class FindingForm : Form
	{
		static MainForm main;

		public FindingForm()
		{
			InitializeComponent();
		}

		public FindingForm(MainForm mainForm)
		{
			InitializeComponent();
			main = mainForm;
		}

		private void SearchButton_Click(object sender, EventArgs e)
		{
			FigureGrid.Rows.Clear();
			if (RectangleCheckBox.Checked || CircleCheckBox.Checked)
			{
				foreach (IFigure figure in main.figures)
				{
					if (figure is Model.Rectangle && RectangleCheckBox.Checked)
					{
						AddToGrid("Rectangle", figure);
					}
					else if (figure is Model.Circle && CircleCheckBox.Checked)
					{
						AddToGrid("Circle", figure);
					}
				}
			}
		}

		public void AddToGrid(string name, IFigure figure)
		{
			if (IsBetween(Convert.ToDouble(SurfaceFirstTextBox.Text),
				Convert.ToDouble(SurfaceSecondTextBox.Text), figure.Surface) &&
				IsBetween(Convert.ToDouble(PerimeterFirstTextBox.Text),
				Convert.ToDouble(PerimeterSecondTextBox.Text), figure.Perimeter))
			{
				FigureGrid.Rows.Add(name, figure.Surface, figure.Perimeter);
			}
		}

		public bool IsBetween(double min, double max, double argument)
		{
			if(argument >= min && argument <= max)
			{
				return true;
			}
			return false;
		}

		private void SurfaceFirstTextBox_Validating(object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (!BlankFieldChecking(out errorMsg))
			{
				SearchButton.Enabled = false;
				SetError(SurfaceFirstTextBox,SurfaceSecondTextBox, errorMsg, sender, e);
			}
			else
			{
				SearchButton.Enabled = true;
				errorMsg = "";
				SetError(SurfaceFirstTextBox, SurfaceSecondTextBox, errorMsg, sender, e);
			}
		}

		private void PerimeterFirstTextBox_Validating(object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (!BlankFieldChecking(out errorMsg))
			{
				SearchButton.Enabled = false;
				SetError(PerimeterFirstTextBox, PerimeterSecondTextBox, errorMsg, sender, e);
			}
			else
			{
				SearchButton.Enabled = true;
				errorMsg = "";
				SetError(PerimeterFirstTextBox, PerimeterSecondTextBox, errorMsg, sender, e);
			}
		}

		private void SurfaceFirstTextBox_KeyPress(object sender, KeyPressEventArgs e)
		{
			if (!(Char.IsDigit(e.KeyChar)))
			{
				if (e.KeyChar != (char)Keys.Back)
				{
					e.Handled = true;
				}
			}
		}

		public void SetError(TextBox firstStr, TextBox secondStr,
			string errorMsg, object sender, CancelEventArgs e)
		{
			this.errorProvider.SetError(SurfaceFirstTextBox, errorMsg);
			this.errorProvider.SetError(SurfaceSecondTextBox, errorMsg);
			this.errorProvider.SetError(PerimeterFirstTextBox, errorMsg);
			this.errorProvider.SetError(PerimeterSecondTextBox, errorMsg);
			if (!ValidValueGap(firstStr.Text, secondStr.Text, out errorMsg))
			{
				e.Cancel = true;
				(sender as TextBox).Select(0, (sender as TextBox).Text.Length);
				this.errorProvider.SetError((sender as TextBox), errorMsg);

			}
		}

		public bool BlankFieldChecking(out string errorMessage)
		{
			if (SurfaceFirstTextBox.Text.Length == 0 || SurfaceSecondTextBox.Text.Length == 0 ||
				PerimeterFirstTextBox.Text.Length == 0 || PerimeterSecondTextBox.Text.Length == 0)
			{
				errorMessage = "All fields must be filled in";
				return false;
			}
			errorMessage = "";
			return true;
		}

		public bool ValidValueGap(string currentStr, string secondStr, out string errorMessage)
		{
			if (currentStr.Length != 0 && secondStr.Length != 0)
			{
				if (Convert.ToDouble(currentStr) > Convert.ToDouble(secondStr))
				{
					errorMessage = "Second value must be more or equal to the first";
					return false;
				}
			}
			errorMessage = "";
			return true;
		}
	}
}
