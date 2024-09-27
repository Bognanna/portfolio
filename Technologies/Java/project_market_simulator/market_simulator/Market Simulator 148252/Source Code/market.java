package com.mycompany.market_simulator;

import java.util.ArrayList;
import java.util.List;

/**
 * Market class
 * 
 * @author Bogna
 */
public class market {

    private String name;
    private String country;
    private String trading_curr;
    private String city;
    private String address;
    
    private List<Float> history_of_prices;
    
    /**
     * Market constructor
     * 
     * @param nam       name
     * @param co        country
     * @param tr_curr   trading currency
     * @param c         city
     * @param ad        address
     */  
    public market(String nam, String co, String tr_curr, String c, String ad){
        name = nam;
        country = co;
        trading_curr = tr_curr;
        city = c;
        address = ad;
        history_of_prices = new ArrayList<Float>();
    }

}
