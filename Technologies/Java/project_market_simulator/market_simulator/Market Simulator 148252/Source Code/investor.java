package com.mycompany.market_simulator;

import static java.lang.Math.abs;
import java.util.Random;

/**
 * Investor class
 * 
 * @author Bogna
 */
public class investor extends player{
    
    private String name;
    private Random rnd;
    
    /**
     * Investor constructor
     * 
     * @param t_p_m     transactions per minute
     * @param p_bear    bear in bear/bull ratio
     * @param p_bull    bull in bear/bull ratio
     * @param p_stop    stop is true, when the user clicks the stop-button, false if the user click the stop-button again
     * @param p_id      identifier of the player
     * @param p_budget  budget of the player
     * @param o_asset   asset which player may buy
     * @param nam       name of the investor
     */
    public investor(int t_p_m, int p_bear, int p_bull, boolean p_stop, int p_id, float p_budget, kapital o_asset, String nam){
        super(t_p_m, p_bear, p_bull, p_stop, p_id, p_budget, o_asset);
        name = nam;
        rnd = new Random();
    }
    
    /**
     * Display name in the terminal
     */
    public void display_name(){
        System.out.println(name);
    }
    
    /**
     * Name getter
     * 
     * @return name
     */
    @Override
    public String getName(){
        return name;
    }
    
    /**
     * Buy the observed asset, update the budget and set new price for the asset
     * 
     * @param asset asset to buy 
     */
    @Override
    public void buy_asset(kapital asset){
        String a_name = asset.getName();
        float a_cost = asset.getCurrent_price();
        budget -= a_cost;
        list_of_assets.add(asset);
        
        System.out.println(name + " bought " + a_name + ": " + a_cost);
        asset.change_current_price(abs(rnd.nextFloat() * 100));
    }
    
    /**
     * Sell the first asset from the list of assets, update budget and set new price for the asset
     */
    @Override
    public void sell_asset(){
        kapital asset = list_of_assets.get(0);
        float a_cost = asset.getCurrent_price();
        String a_name = asset.getName();
        budget += a_cost;
        list_of_assets.remove(0);
        
        System.out.println(name + " sold " + a_name + ": " + a_cost);
        asset.change_current_price(abs(rnd.nextFloat() * 100) * (-1));
    }
}
