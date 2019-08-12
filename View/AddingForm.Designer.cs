namespace View
{
	partial class AddingForm
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

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.CancelButton = new System.Windows.Forms.Button();
			this.AddButton = new System.Windows.Forms.Button();
			this.errorProvider = new System.Windows.Forms.ErrorProvider(this.components);
			this.AddingGroupBox = new System.Windows.Forms.GroupBox();
			this.objectControl = new View.ObjectControl();
			this.ModifyButton = new System.Windows.Forms.Button();
			this.objectControl1 = new View.ObjectControl();
			((System.ComponentModel.ISupportInitialize)(this.errorProvider)).BeginInit();
			this.AddingGroupBox.SuspendLayout();
			this.SuspendLayout();
			// 
			// CancelButton
			// 
			this.CancelButton.Location = new System.Drawing.Point(115, 130);
			this.CancelButton.Name = "CancelButton";
			this.CancelButton.Size = new System.Drawing.Size(75, 23);
			this.CancelButton.TabIndex = 9;
			this.CancelButton.Text = "Cancel";
			this.CancelButton.UseVisualStyleBackColor = true;
			this.CancelButton.Click += new System.EventHandler(this.CancelButton_Click);
			// 
			// AddButton
			// 
			this.AddButton.Location = new System.Drawing.Point(6, 130);
			this.AddButton.Name = "AddButton";
			this.AddButton.Size = new System.Drawing.Size(75, 23);
			this.AddButton.TabIndex = 8;
			this.AddButton.Text = "Add";
			this.AddButton.UseVisualStyleBackColor = true;
			this.AddButton.Click += new System.EventHandler(this.AddButton_Click);
			// 
			// errorProvider
			// 
			this.errorProvider.ContainerControl = this;
			// 
			// AddingGroupBox
			// 
			this.AddingGroupBox.Controls.Add(this.objectControl);
			this.AddingGroupBox.Controls.Add(this.CancelButton);
			this.AddingGroupBox.Controls.Add(this.AddButton);
			this.AddingGroupBox.Controls.Add(this.ModifyButton);
			this.AddingGroupBox.Location = new System.Drawing.Point(12, 12);
			this.AddingGroupBox.Name = "AddingGroupBox";
			this.AddingGroupBox.Size = new System.Drawing.Size(196, 158);
			this.AddingGroupBox.TabIndex = 0;
			this.AddingGroupBox.TabStop = false;
			this.AddingGroupBox.Text = "Figure adding";
			// 
			// objectControl
			// 
			this.objectControl.Location = new System.Drawing.Point(5, 19);
			this.objectControl.Name = "objectControl";
			this.objectControl.ReadOnly = true;
			this.objectControl.Size = new System.Drawing.Size(185, 112);
			this.objectControl.TabIndex = 10;
			// 
			// ModifyButton
			// 
			this.ModifyButton.Enabled = false;
			this.ModifyButton.Location = new System.Drawing.Point(6, 130);
			this.ModifyButton.Name = "ModifyButton";
			this.ModifyButton.Size = new System.Drawing.Size(75, 23);
			this.ModifyButton.TabIndex = 11;
			this.ModifyButton.Text = "Modify";
			this.ModifyButton.UseVisualStyleBackColor = true;
			this.ModifyButton.Visible = false;
			this.ModifyButton.Click += new System.EventHandler(this.ModifyButton_Click);
			// 
			// objectControl1
			// 
			this.objectControl1.Location = new System.Drawing.Point(2, 19);
			this.objectControl1.Name = "objectControl1";
			this.objectControl1.ReadOnly = true;
			this.objectControl1.Size = new System.Drawing.Size(191, 112);
			this.objectControl1.TabIndex = 0;
			// 
			// AddingForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(214, 177);
			this.Controls.Add(this.AddingGroupBox);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.MaximumSize = new System.Drawing.Size(230, 216);
			this.MinimumSize = new System.Drawing.Size(230, 216);
			this.Name = "AddingForm";
			this.Text = "AddingForm";
			((System.ComponentModel.ISupportInitialize)(this.errorProvider)).EndInit();
			this.AddingGroupBox.ResumeLayout(false);
			this.ResumeLayout(false);

		}

		#endregion
		private System.Windows.Forms.Button CancelButton;
		private System.Windows.Forms.Button AddButton;
		private System.Windows.Forms.ErrorProvider errorProvider;
		private System.Windows.Forms.GroupBox AddingGroupBox;
		private ObjectControl objectControl;
		private ObjectControl objectControl1;
		private System.Windows.Forms.Button ModifyButton;
	}
}