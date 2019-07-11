using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace View
{
	public partial class AddingForm : Form
	{
		static MainForm main;

		public AddingForm()
		{
			InitializeComponent();
		}

		public AddingForm(MainForm mainForm)
		{
			InitializeComponent();
			main = mainForm;
		}

		private void CircleRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			RectangleGroupBox.Enabled = false;
			CircleGroupBox.Enabled = true;
			WidthTextBox.Text = "";
			LengthTextBox.Text = "";
			this.errorProvider.SetError(WidthTextBox, "");
			this.errorProvider.SetError(LengthTextBox, "");
		}

		private void RectangleRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			RectangleGroupBox.Enabled = true;
			CircleGroupBox.Enabled = false;
			RadiusTextBox.Text = "";
			this.errorProvider.SetError(RadiusTextBox, "");
		}

		private void CancelButton_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void AddButton_Click(object sender, EventArgs e)
		{
			if (CircleRadioButton.Checked)
			{
				double radius = Convert.ToDouble(RadiusTextBox.Text);
				main.CircleToList(radius);
			}
			else
			{
				double width = Convert.ToDouble(WidthTextBox.Text);
				double length = Convert.ToDouble(LengthTextBox.Text);
				main.RectangleToList(width, length);
			}
			this.Close();
		}

		private void RadiusTextBox_KeyPress(object sender, KeyPressEventArgs e)
		{
			if (!Char.IsDigit(e.KeyChar))
			{
				if (e.KeyChar != (char)Keys.Back)
				{
					e.Handled = true;
				}
			}
		}

		private void RadiusTextBox_Validating(object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (IsZero(RadiusTextBox.Text, out errorMsg)){
				AddButton.Enabled = false;
				this.errorProvider.SetError(RadiusTextBox, errorMsg);
			}
			else
			{
				AddButton.Enabled = true;
				errorMsg = "";
				this.errorProvider.SetError(RadiusTextBox, errorMsg);
			}
		}

		public bool IsZero(string field, out string errorMessage)
		{
			foreach(char letter in field)
			{
				if (letter != '0')
				{
					errorMessage = "";
					return false;
				}
			}
			errorMessage = "Value mustn't be equal 0 or empty";
			return true;
		}

		private void WidthTextBox_Validating(object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (IsZero(WidthTextBox.Text, out errorMsg) && IsZero(LengthTextBox.Text, out errorMsg))
			{
				SetError(false, errorMsg, errorMsg);
			}
			else if (IsZero(WidthTextBox.Text, out errorMsg) && !IsZero(LengthTextBox.Text, out errorMsg))
			{
				SetError(false, errorMsg, "");
			}
			else if (!IsZero(WidthTextBox.Text, out errorMsg) && IsZero(LengthTextBox.Text, out errorMsg))
			{
				SetError(false, "", errorMsg);
			}
			else 
			{
				SetError(true, "", "");
			}
		}

		public void SetError(bool ButtonEnabled, string WidthErr, string LengthErr)
		{
			AddButton.Enabled = ButtonEnabled;
			this.errorProvider.SetError(WidthTextBox, WidthErr);
			this.errorProvider.SetError(LengthTextBox, LengthErr);
		}
	}
}
