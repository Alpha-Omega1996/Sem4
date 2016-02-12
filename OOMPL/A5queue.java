import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.awt.Graphics;
public class queue extends Applet implements ActionListener {
	TextField t1, t2;
	Button b1, b2, b3, b4;
	TextArea T; 
	static int n;
	int i, front=0, rear=0, item, count=0;
	String s1, s2;
	int queue[];
	public void init() {
		t1 = new TextField(10);
		add(t1);
		t1.setText("");
		Button b4 =  new Button("queue Limit");
		add(b4);
		b4.addActionListener(this);
		t2 = new TextField(10);
		add(t2);
		t2.setText("");
		Button b1 =  new Button("Push");
		add(b1);
		b1.addActionListener(this);
		Button b2 = new Button("Pop");
		add(b2);
		b2.addActionListener(this);
		Button b3 = new Button("Display");
		add(b3);
		b3.addActionListener(this);
		T = new TextArea(20, 30);
		add(T);
	}

	public void actionPerformed(ActionEvent e){

		Button source = (Button)e.getSource();
		if(source.getLabel() == "queue Limit"){
			try {  
				s1 = t1.getText();
     				n = Integer.parseInt(s1);  
   				queue = new int[n];  
   			}   
  			catch(Exception e1) {  
   				System.out.println(e1.getMessage());  
   			} 	
		} 
      		if(source.getLabel() == "Push"){ 
			try {  
   				if(count < n) {  
					s2 = t2.getText(); 
    					item = Integer.parseInt(s2);  
    					queue[rear]=item;  
					t2.setText("");
     					rear++;  
    					count++;  
    				}  
   				else{  
					T.setText("");
    					T.setText("queue IS FULL\n"); 
					t2.setText("");
				} 
   			}  
  			catch(Exception e1) {  
   				System.out.println(e1.getMessage());  
   			}  
  		} 
		if (source.getLabel() == "Pop") {
				if(count!=0) {  
					T.setText("");
    					T.setText("The item deleted is: "+queue[front]+"\n");  
    					front++;  
    					count--;  
    				}  
   				else{
					T.setText("");
    					T.setText("queue IS EMPTY\n");  
				}
  				if(rear==n)  
   					rear=0;  
		}
		if (source.getLabel() == "Display") {
				int m=0;
				T.setText("");  
   				if(count==0) {
					T.setText("");
   					T.setText("queue IS EMPTY\n");  
				}
   				else {  
   					for(i=front;m<count;i++,m++)  
   						T.append(" "+queue[i]);
   				}  
  		}  
	}
}
