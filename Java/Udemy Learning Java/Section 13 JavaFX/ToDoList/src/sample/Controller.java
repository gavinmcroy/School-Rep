package sample;

import sample.datamodel.ToDoItem;

import java.time.LocalDate;
import java.time.Month;
import java.util.List;

public class Controller {

    private List<ToDoItem> toDoItems;

    public void initialize(){
        ToDoItem item1 = new ToDoItem("Birthday Card","Card",
                LocalDate.of(2019, Month.APRIL,23));
    }

}
