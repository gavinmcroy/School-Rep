package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class Controller {

    @FXML
    private TextField textField;
    @FXML
    private Button buttonClick;
    @FXML
    private Button buttonClose;

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
    }

    @FXML
    public void handleKeyReleased() {
        String name = textField.getText();
        boolean disabledButtons = name.isEmpty() || name.trim().isEmpty();
        buttonClick.setDisable(disabledButtons);
        buttonClose.setDisable(disabledButtons);
    }
}
