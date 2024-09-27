package com.mycompany.market_simulator;

/**
 * Commodity class
 * 
 * @author Bogna
 */
public class commodity extends kapital{
    
    private String trading_unit;
    
    /**
     * Commodity constructor
     * 
     * @param nam       name
     * @param min_p     minimum price of the asset
     * @param max_p     maximal price of the asset
     * @param curr_p    current price of the asset
     * @param id        identifier of the asset
     * @param trad_u    unit in which player can buy it
     */
    public commodity(String name, float p_min, float p_max, float p_current, int id, String trad_u){
        super(name, p_min, p_max, p_current, id);
        trading_unit = trad_u;
    }
    
}
