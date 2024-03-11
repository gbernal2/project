package cite.library;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class myFrame extends JFrame{

	public myFrame(){

		new LoginViewer(this);

		setTitle("JAVA LOGIN SYSTEM");
		setSize(420,420);
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);

	}



}