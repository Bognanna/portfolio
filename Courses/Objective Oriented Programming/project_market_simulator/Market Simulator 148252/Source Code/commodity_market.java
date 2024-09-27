package com.mycompany.market_simulator;

import java.util.ArrayList;
import java.util.List;

/**
 *  Commodity market class
 * 
 * @author Bogna
 */
public class commodity_market extends market{
    private List<commodity> list_of_com;
  
    /**
     * Commodity market constructor
     * 
     * @param nam       name
     * @param co        country
     * @param tr_curr   trading currency
     * @param c         city
     * @param ad        address
     */
    public commodity_market(String nam, String co, String tr_curr, String c, String ad){
        super(nam, co, tr_curr, c, ad);
        list_of_com = new ArrayList<commodity>();
    }
    
    /**
     * Add commodity to the market
     * 
     * @param c commodity
     */
    public void add_to_the_list(commodity c){
        list_of_com.add(c);
    }

}
