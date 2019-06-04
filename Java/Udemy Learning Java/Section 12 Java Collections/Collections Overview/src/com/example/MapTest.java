package com.example;

import java.util.HashMap;
import java.util.Map;

public class MapTest {

    public static void main(String[] args) {
        Map<String, String> languages = new HashMap<>();
        languages.put("Java", "A compiled High level OOP Language");
        languages.put("Python", " A interpreted high level programming langauge ");
        languages.put("Algol", "Algorithmic language");
        languages.put("BASIC ", "Beginners all purpose instruction code");
        languages.put("LISP", "There in lies madness ");

        if (languages.containsKey("Java")) {
            System.out.println("Java is already in the map! ");
        } else {
            languages.put("Java", "Course about java");
        }
        System.out.println(languages.get("Java"));
        languages.put("Java", "Course about java");
        System.out.println(languages.get("Java"));

        System.out.println("=======================");
        for (String key : languages.keySet()) {
            System.out.println(key + " : " + languages.get(key));
        }
        System.out.println("==========================================");

//        languages.remove("LISP");

        if(languages.remove("Algol","Algorithmic language")){
            System.out.println("Algo removed");
        }else{
            System.out.println("Algo not removed");
        }

        System.out.println(languages.replace("LISP","functional programming language"));
        System.out.println(languages.replace("1234","this wont work !"));
        for(String key: languages.keySet()){
            System.out.println(key+" : "+languages.get(key));
        }
    }
}
