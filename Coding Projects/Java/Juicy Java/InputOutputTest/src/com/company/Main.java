package com.company;

import java.io.File;
import java.io.IOException;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class Main {

    public static void main(String[] args) throws IOException {
        int width = 500;
        int height = 331;
        BufferedImage image = null;
        File file = null;

        try {
            file = new File("/Users/gavintaylormcroy/Desktop");
            image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
            image = ImageIO.read(file);
            System.out.println("Reading completed");
        } catch (IOException e) {
            System.out.println("Error: " + e);
        }

        try {
            file = new File("/Users/gavintaylormcroy/Desktop");
            ImageIO.write(image, "jpg", file);
            System.out.println("Writing completed");
        } catch (IOException e) {
            System.out.println("Error " + e);
        }
    }
}
