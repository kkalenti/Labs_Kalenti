namespace View
{
	partial class ObjectControl
	{
		/// <summary> 
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary> 
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Component Designer generated code

		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.AddingGroupBox = new System.Windows.Forms.GroupBox();
			this.CircleGroupBox = new System.Windows.Forms.GroupBox();
			this.RadiusTextBox = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.RectangleGroupBox = new System.Windows.Forms.GroupBox();
			this.LengthTextBox = new System.Windows.Forms.TextBox();
			this.WidthTextBox = new System.Windows.Forms.TextBox();
			this.Width = new System.Windows.Forms.Label();
			this.Length = new System.Windows.Forms.Label();
			this.RectangleRadioButton = new System.Windows.Forms.RadioButton();
			this.CircleRadioButton = new System.Windows.Forms.RadioButton();
			this.errorProvider = new System.Windows.Forms.ErrorProvider(this.components);
			this.AddingGroupBox.SuspendLayout();
			this.CircleGroupBox.SuspendLayout();
			this.RectangleGroupBox.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.errorProvider)).BeginInit();
			this.SuspendLayout();
			// 
			// AddingGroupBox
			// 
			this.AddingGroupBox.Controls.Add(this.RectangleGroupBox);
			this.AddingGroupBox.Controls.Add(this.RectangleRadioButton);
			this.AddingGroupBox.Controls.Add(this.CircleRadioButton);
			this.AddingGroupBox.Controls.Add(this.CircleGroupBox);
			this.AddingGroupBox.Location = new System.Drawing.Point(3, 3);
			this.AddingGroupBox.Name = "AddingGroupBox";
			this.AddingGroupBox.Size = new System.Drawing.Size(190, 126);
			this.AddingGroupBox.TabIndex = 1;
			this.AddingGroupBox.TabStop = false;
			this.AddingGroupBox.Text = "Figure";
			// 
			// CircleGroupBox
			// 
			this.CircleGroupBox.Controls.Add(this.RadiusTextBox);
			this.CircleGroupBox.Controls.Add(this.label1);
			this.CircleGroupBox.Enabled = false;
			this.CircleGroupBox.Location = new System.Drawing.Point(5, 44);
			this.CircleGroupBox.Name = "CircleGroupBox";
			this.CircleGroupBox.Size = new System.Drawing.Size(179, 49);
			this.CircleGroupBox.TabIndex = 7;
			this.CircleGroupBox.TabStop = false;
			this.CircleGroupBox.Text = "Circle";
			// 
			// RadiusTextBox
			// 
			this.RadiusTextBox.Location = new System.Drawing.Point(56, 19);
			this.RadiusTextBox.MaxLength = 7;
			this.RadiusTextBox.Name = "RadiusTextBox";
			this.RadiusTextBox.Size = new System.Drawing.Size(100, 20);
			this.RadiusTextBox.TabIndex = 3;
			this.RadiusTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.RadiusTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.RadiusTextBox_KeyPress);
			this.RadiusTextBox.Validating += new System.ComponentModel.CancelEventHandler(this.RadiusTextBox_Validating);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(7, 22);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(43, 13);
			this.label1.TabIndex = 2;
			this.label1.Text = "Radius:";
			// 
			// RectangleGroupBox
			// 
			this.RectangleGroupBox.Controls.Add(this.LengthTextBox);
			this.RectangleGroupBox.Controls.Add(this.WidthTextBox);
			this.RectangleGroupBox.Controls.Add(this.Width);
			this.RectangleGroupBox.Controls.Add(this.Length);
			this.RectangleGroupBox.Location = new System.Drawing.Point(5, 44);
			this.RectangleGroupBox.Name = "RectangleGroupBox";
			this.RectangleGroupBox.Size = new System.Drawing.Size(179, 76);
			this.RectangleGroupBox.TabIndex = 6;
			this.RectangleGroupBox.TabStop = false;
			this.RectangleGroupBox.Text = "Rectangle";
			// 
			// LengthTextBox
			// 
			this.LengthTextBox.Location = new System.Drawing.Point(58, 43);
			this.LengthTextBox.MaxLength = 7;
			this.LengthTextBox.Name = "LengthTextBox";
			this.LengthTextBox.Size = new System.Drawing.Size(100, 20);
			this.LengthTextBox.TabIndex = 6;
			this.LengthTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.LengthTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.RadiusTextBox_KeyPress);
			this.LengthTextBox.Validating += new System.ComponentModel.CancelEventHandler(this.WidthTextBox_Validating);
			// 
			// WidthTextBox
			// 
			this.WidthTextBox.Location = new System.Drawing.Point(58, 19);
			this.WidthTextBox.MaxLength = 7;
			this.WidthTextBox.Name = "WidthTextBox";
			this.WidthTextBox.Size = new System.Drawing.Size(100, 20);
			this.WidthTextBox.TabIndex = 5;
			this.WidthTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.WidthTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.RadiusTextBox_KeyPress);
			this.WidthTextBox.Validating += new System.ComponentModel.CancelEventHandler(this.WidthTextBox_Validating);
			// 
			// Width
			// 
			this.Width.AutoSize = true;
			this.Width.Location = new System.Drawing.Point(7, 22);
			this.Width.Name = "Width";
			this.Width.Size = new System.Drawing.Size(38, 13);
			this.Width.TabIndex = 2;
			this.Width.Text = "Width:";
			// 
			// Length
			// 
			this.Length.AutoSize = true;
			this.Length.Location = new System.Drawing.Point(7, 46);
			this.Length.Name = "Length";
			this.Length.Size = new System.Drawing.Size(43, 13);
			this.Length.TabIndex = 4;
			this.Length.Text = "Length:";
			// 
			// RectangleRadioButton
			// 
			this.RectangleRadioButton.AutoSize = true;
			this.RectangleRadioButton.Location = new System.Drawing.Point(87, 23);
			this.RectangleRadioButton.Name = "RectangleRadioButton";
			this.RectangleRadioButton.Size = new System.Drawing.Size(74, 17);
			this.RectangleRadioButton.TabIndex = 1;
			this.RectangleRadioButton.TabStop = true;
			this.RectangleRadioButton.Text = "Rectangle";
			this.RectangleRadioButton.UseVisualStyleBackColor = true;
			this.RectangleRadioButton.CheckedChanged += new System.EventHandler(this.RectangleRadioButton_CheckedChanged);
			// 
			// CircleRadioButton
			// 
			this.CircleRadioButton.AutoSize = true;
			this.CircleRadioButton.Location = new System.Drawing.Point(14, 23);
			this.CircleRadioButton.Name = "CircleRadioButton";
			this.CircleRadioButton.Size = new System.Drawing.Size(51, 17);
			this.CircleRadioButton.TabIndex = 0;
			this.CircleRadioButton.TabStop = true;
			this.CircleRadioButton.Text = "Circle";
			this.CircleRadioButton.UseVisualStyleBackColor = true;
			this.CircleRadioButton.CheckedChanged += new System.EventHandler(this.CircleRadioButton_CheckedChanged);
			// 
			// errorProvider
			// 
			this.errorProvider.ContainerControl = this;
			// 
			// ObjectControl
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.Controls.Add(this.AddingGroupBox);
			this.Name = "ObjectControl";
			this.Size = new System.Drawing.Size(196, 129);
			this.AddingGroupBox.ResumeLayout(false);
			this.AddingGroupBox.PerformLayout();
			this.CircleGroupBox.ResumeLayout(false);
			this.CircleGroupBox.PerformLayout();
			this.RectangleGroupBox.ResumeLayout(false);
			this.RectangleGroupBox.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.errorProvider)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.GroupBox AddingGroupBox;
		private System.Windows.Forms.GroupBox RectangleGroupBox;
		private System.Windows.Forms.TextBox LengthTextBox;
		private System.Windows.Forms.TextBox WidthTextBox;
		private System.Windows.Forms.GroupBox CircleGroupBox;
		private System.Windows.Forms.TextBox RadiusTextBox;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label Width;
		private System.Windows.Forms.Label Length;
		private System.Windows.Forms.RadioButton RectangleRadioButton;
		private System.Windows.Forms.RadioButton CircleRadioButton;
		private System.Windows.Forms.ErrorProvider errorProvider;
	}
}
