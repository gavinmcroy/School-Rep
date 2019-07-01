package sample;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class Controller {

    @FXML
    private TextField textField;
    @FXML
    private Button buttonClick;
    @FXML
    private Button buttonClose;
    @FXML
    private CheckBox checkBox;
    @FXML
    private Label label;

    @FXML
    public void initialize() {
        buttonClick.setDisable(true);
        buttonClose.setDisable(true);
    }

    @FXML
    public void onButtonClick(ActionEvent event) {
        if (event.getSource() == buttonClick) {
            System.out.println("Hello " + textField.getText());
        } else if (event.getSource() == buttonClose) {
            System.out.println("Close " + textField.getText());
        }
        Runnable task = new Runnable(){
            @Override
            public void run() {
                try{
                    String whichThreadIsAsleep = Platform.isFxApplicationThread() ? "UI Thread": "Background Thread";
                    System.out.println("sleep time " +whichThreadIsAsleep);
                    Thread.sleep(10000);
                    Platform.runLater(new Runnable() {
                        @Override
                        public void run() {
                            String whichThreadIsAsleep = Platform.isFxApplicationThread() ? "UI Thread": "Background Thread";
                            System.out.println("updating label on " +whichThreadIsAsleep);
                            label.setText("Thread has awoken");
                        }
                    });
                }catch(InterruptedException e){

                }
            }
        };
        new Thread(task).start();

        if(checkBox.isSelected()){
            textField.clear();
            buttonClick.setDisable(true);
            buttonClose.setDisable(true);
        }
    }

    @FXML
    public void handleKeyReleased() {
        String name = textField.getText();
        boolean disabledButtons = name.isEmpty() || name.trim().isEmpty();
        buttonClick.setDisable(disabledButtons);
        buttonClose.setDisable(disabledButtons);
    }

    public void handleChange(){
        System.out.println("Checkbox is "+(checkBox.isSelected() ? "Checked":"Unchecked"));
    }

}
