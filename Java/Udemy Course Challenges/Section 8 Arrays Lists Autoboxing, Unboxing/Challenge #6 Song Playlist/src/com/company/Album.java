package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Album {

    private Scanner scanner = new Scanner(System.in);
    private ArrayList<Song> songArrayList = new ArrayList<>();
    private String albumName;


    public Album(String albumName) {
        this.albumName = albumName;
    }

    public void addSong() {
        System.out.println("Enter the song name ");
        String title = scanner.nextLine();
        System.out.println("Enter the duration ");
        boolean hasNextBoolean = scanner.hasNextBoolean();
        if (hasNextBoolean) {
            double duration = scanner.nextDouble();
            songArrayList.add(new Song(title, duration));
        } else {
            System.out.println("Enter a valid number");
        }
    }

    public ArrayList<Song> getSongArrayList() {
        return songArrayList;
    }

    public String getAlbumName() {
        return albumName;
    }

    public static void testing(){
        System.out.println("Static is handy");
    }
}
