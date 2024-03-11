package cite.library;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class RegisterViewer{

	private BufferedWriter writer;

	RegisterViewer(JFrame myFrame){

		try{

			writer = new BufferedWriter(new FileWriter("user.dat",true));

		}

		catch(IOException e){

			e.printStackTrace();

		}


		JPanel regPanel = new JPanel();
		regPanel.setBounds(0,0,420,420);
		regPanel.setBackground(new Color(0,0,0));
		regPanel.setLayout(null);
		myFrame.add(regPanel);

		JLabel userLabel = new JLabel();
		userLabel.setText("create username");
		userLabel.setBounds(80,80,150,100);
		userLabel.setForeground(new Color(255,255,255));
		regPanel.add(userLabel);

		JLabel passLabel = new JLabel();
		passLabel.setText("create password");
		passLabel.setBounds(80,150,150,100);
		passLabel.setForeground(new Color(255,255,255));
		regPanel.add(passLabel);

		JTextField userTxtfield = new JTextField();
		userTxtfield.setBounds(185,110,175,35);
		regPanel.add(userTxtfield);

		JTextField passTxtfield = new JTextField();
		passTxtfield.setBounds(185,185,175,35);
		regPanel.add(passTxtfield);

		JButton regButton = new JButton();
		regButton.setText("Register");
		regButton.setBounds(35,270,145,60);
		regPanel.add(regButton);
		regButton.addActionListener(new ActionListener(){

			public void actionPerformed(ActionEvent e){

				String username = userTxtfield.getText();
				String password = passTxtfield.getText();

				if(username.equals("") && password.equals("") || username.equals(" ") && password.equals(" ")){

					JOptionPane.showMessageDialog(myFrame,"Invalid input please try again");

				}

				else{

					writeToFile(username,password);

					JOptionPane.showMessageDialog(myFrame,"Registration Successful");

					myFrame.getContentPane().removeAll();
					myFrame.repaint();

					new LoginViewer(myFrame);

				}

			}

		});

		JButton cancelButton = new JButton();
		cancelButton.setText("Cancel");
		cancelButton.setBounds(210,270,145,60);
		regPanel.add(cancelButton);
		cancelButton.addActionListener(new ActionListener(){

			public void actionPerformed(ActionEvent e){

				myFrame.getContentPane().removeAll();
				myFrame.repaint();

				new LoginViewer(myFrame);

			}

		});




	}

	private void writeToFile(String username, String password){

		try{

			writer.write(username + "," + password);
			writer.newLine();

			writer.flush();

		}

		catch(IOException e){

			e.printStackTrace();

		}

	}

}