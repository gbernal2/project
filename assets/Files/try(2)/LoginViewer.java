package cite.library;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class LoginViewer{

	LoginViewer(JFrame myFrame){


		JPanel loginPanel = new JPanel();
		loginPanel.setBounds(0,0,420,420);
		loginPanel.setBackground(new Color(50,50,50));
		loginPanel.setLayout(null);
		myFrame.add(loginPanel);

		JLabel userLabel = new JLabel();
		userLabel.setText("username");
		userLabel.setBounds(80,80,150,100);
		userLabel.setForeground(new Color(255,255,255));
		loginPanel.add(userLabel);

		JLabel passLabel = new JLabel();
		passLabel.setText("password");
		passLabel.setBounds(80,150,150,100);
		passLabel.setForeground(new Color(255,255,255));
		loginPanel.add(passLabel);

		JTextField userTxtfield = new JTextField();
		userTxtfield.setBounds(150,110,175,35);
		loginPanel.add(userTxtfield);

		JPasswordField passTxtfield = new JPasswordField();
		passTxtfield.setBounds(150,185,175,35);
		loginPanel.add(passTxtfield);

		JButton loginButton = new JButton();
		loginButton.setText("Log in");
		loginButton.setBounds(35,270,145,60);
		loginPanel.add(loginButton);
		loginButton.addActionListener(new ActionListener(){

			public void actionPerformed(ActionEvent e){

				String enteredUsername = userTxtfield.getText();
				char[] enteredPassword = passTxtfield.getPassword();

				if(isValidLogin(enteredUsername,enteredPassword)){

					JOptionPane.showMessageDialog(myFrame,"WELCOME " + enteredUsername);

				}

				else{

					JOptionPane.showMessageDialog(myFrame,"Invalid username and password");

				}

			}

		});

		JButton regButton = new JButton();
		regButton.setText("Register");
		regButton.setBounds(210,270,145,60);
		loginPanel.add(regButton);
		regButton.addActionListener(new ActionListener(){

			public void actionPerformed(ActionEvent e){

				myFrame.getContentPane().removeAll();
				myFrame.repaint();

				new RegisterViewer(myFrame);

			}

		});




	}

	private boolean isValidLogin(String enteredUsername, char[] enteredPassword){

		try(BufferedReader reader = new BufferedReader(new FileReader("user.dat"))){

			String line;

			while((line = reader.readLine()) != null){

				String[] credentials = line.split(",");

				if(credentials.length == 2){

					String storedUsername = credentials[0];
					String storedPassword = credentials[1];

					if(storedUsername.equals(enteredUsername) && storedPassword.equals(new String(storedPassword))){

						return true;

					}

				}

			}

		}

		catch(IOException ex){

			ex.printStackTrace();

		}

		return false;

	}

}