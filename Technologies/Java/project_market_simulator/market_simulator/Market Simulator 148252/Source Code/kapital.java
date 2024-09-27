package com.mycompany.market_simulator;

/**
 * Kapital class
 * 
 * @author Bogna
 */
public class kapital {
    
    private int index;
    private String name;
    private float current_price;
    private float min_price;
    private float max_price;
    
    /**
     * Kapital (asset) constructor
     * 
     * @param nam       name
     * @param min_p     minimum price of the asset
     * @param max_p     maximal price of the asset
     * @param curr_p    current price of the asset
     * @param id        identifier of the asset
     */
    public kapital(String nam, float min_p, float max_p, float curr_p, int id){
        name = new String();
        name = nam;
        min_price = min_p;
        max_price = max_p;
        current_price = curr_p;
        index = id;
    }
    
    /**
     * Name getter
     * 
     * @return name name
     */
    public String getName() {
        return name;
    }

    /**
     * Name setter
     * 
     * @param name name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Current price getter
     * 
     * @return current price
     */
    public float getCurrent_price() {
        return current_price;
    }

    /**
     * Current price setter
     * 
     * @param current_price current price
     */
    public void setCurrent_price(float current_price) {
        this.current_price = current_price;
    }

    /**
     * Minimum price getter
     * 
     * @return  minimum price
     */
    public float getMin_price() {
        return min_price;
    }

    /**
     * Minimum price setter
     * 
     * @param min_price  minimup price
     */
    public void setMin_price(float min_price) {
        this.min_price = min_price;
    }

    /**
     * Maximum price getter
     * 
     * @return  maximum price
     */
    public float getMax_price() {
        return max_price;
    }

    /**
     * Maximum price setter
     * 
     * @param max_price  maximum price
     */
    public void setMax_price(float max_price) {
        this.max_price = max_price;
    }
    
    /**
     * Change the current price, if it is bigger than max_price, change maximal price, if it is lower than minimal price, change min_price
     * 
     * @param n new current price
     */
    public synchronized void change_current_price(float n){
        
        current_price = Math.max(current_price + n, 0);
        
        if(current_price > max_price){
            max_price = current_price;
        }
        
        if(current_price < min_price){
            min_price = current_price;
        }
    }
}
