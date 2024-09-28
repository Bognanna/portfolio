library(showtext)
library(ggplot2)
library(dplyr)
library(tidyr)
library(png)
library(grid)
library(gganimate)
library(gifski)
library(scales)
library(plotly)

font_add_google("Montserrat")
showtext_auto()

pp_blue = "#006288"

gold <- read.csv("Gold prices.csv")
exchange <- read.csv("CurrencyExchangeRates.csv")
big <- read.csv("World_Development_Indicators.csv")

bh_diff <- read.csv("Bitcoin/BCHAIN-DIFF.CSV")
bh_hrate <- read.csv("Bitcoin/BCHAIN-HRATE.CSV")
bh_mkpru <- read.csv("Bitcoin/BCHAIN-MKPRU.CSV")
bh_trvou <- read.csv("Bitcoin/BCHAIN-TRVOU.CSV")
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
tidy_gold <- gold %>%
  gather("currency", "value", 2:7)

tidy_gold$Date <- as.Date(tidy_gold$Date, '%Y-%m-%d')

x_from = as.Date('2000-01-01', '%Y-%m-%d')
x_from2 = as.Date('2017-01-01', '%Y-%m-%d')
x_to = as.Date('2021-09-01', '%Y-%m-%d')
x_to2 = as.Date('2015-01-01', '%Y-%m-%d')

tidy_gold %>%
  filter(currency != "USD..PM." & currency != "GBP..PM." & currency != "EURO..PM.") %>%
  ggplot(aes(x = Date, y=value, group = currency)) + geom_line(aes(col=factor(currency))) +
  coord_cartesian(xlim=c(x_from,x_to)) + 
  ggtitle("Gold Prices", subtitle="2000 - 2021") + xlab("Year") + ylab("Value") +
  scale_y_continuous(breaks=seq(0, 2100, 500), labels = function(x){paste0(x/1000, 'K')}) +
  scale_color_manual(name="", 
                     labels = c("Euro", 
                                "Funt", 
                                "Dollar"), 
                     values = c("#2980b9", 
                                "#7fb3d5", 
                                "#839192")) +
  theme_bw() + 
  theme(legend.position="bottom", legend.box = "horizontal") +
  theme(plot.title = element_text(size = 30,
                                  family = "Montserrat",
                                  color = pp_blue,
                                  face = "bold"),
        plot.subtitle = element_text(size = 15,
                                     family = "Calibri",
                                     color = pp_blue)) +
  theme(panel.grid.major = element_blank(), 
        panel.grid.minor = element_blank(), 
        panel.border = element_blank(),
        axis.title = element_blank(),
        axis.ticks = element_blank()) +
  theme(legend.text = element_text(size=12))

 #annotation_custom(g_pic, xmin=x_from2, xmax=x_to, ymin=0, ymax=750)
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
tidy_exchange <- exchange %>%
  gather("currency", "value", 2:52)

tidy_exchange$Date <- as.Date(tidy_exchange$Date, '%Y-%m-%d')
tidy_exchange$Date <- format(tidy_exchange$Date, format = "%Y") #problematic line
tidy_exchange = mutate(tidy_exchange, Date=as.integer(Date))


tidy_exchange <- na.omit(tidy_exchange)

grouped_tidy_exchange <- tidy_exchange %>%
  group_by(Date, currency, .add = TRUE) %>%
  summarise(value = mean(value))


g <- grouped_tidy_exchange %>%
  ggplot(aes(x = currency, y = value, frame = Date)) + geom_bar(stat = "identity", color = pp_blue, fill = pp_blue) +
  theme_minimal() +
  ggtitle("Price of the one dollar", subtitle="1996 - 2018") + xlab("Currency") + ylab("Value in log scale") +
  theme(plot.title = element_text(size = 30,
                                  family = "Montserrat",
                                  color = pp_blue,
                                  face = "bold"),
        plot.subtitle = element_text(size = 15,
                                     family = "Calibri",
                                     color = pp_blue)) +
  theme(panel.grid.major = element_blank(),
        panel.grid.minor = element_blank(),
        panel.border = element_blank(),
        axis.text.x = element_blank(),
        axis.text.y = element_text(size = 5)) +
  scale_y_continuous(trans = 'log2') +
  coord_flip() +
  transition_time(Date) +
  ease_aes('linear') +
  labs(title = 'Year {frame_time}') 
  
animate(g, renderer = gifski_renderer())

#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
tidy_big <- big %>%
  gather("year", "value", 5:55)

tidy_big$year <- as.Date(tidy_big$year, 'X%Y..YR%Y.')
tidy_big$year <- format(tidy_big$year, format = "%Y")
tidy_big = mutate(tidy_big, year=as.integer(year))

tidy_big_2018 <- tidy_big %>%
  filter(tidy_big$year == 2018)

tidy_big_2018 = mutate(tidy_big_2018, value=as.integer(value))
tidy_big_2018 <- na.omit(tidy_big_2018)

tidy_big_2018 <- tidy_big_2018 %>%
  filter(tidy_big_2018$Series.Code == "SP.POP.TOTL")

tidy_big_2018 <- tidy_big_2018 %>%
  arrange(-value)

tidy_big_2018 <- tidy_big_2018 %>%
  filter(tidy_big_2018$Country.Code != "HIC" & tidy_big_2018$Country.Code != "LIC")

total = sum(tidy_big_2018$value)

tidy_big_2018 <- tidy_big_2018 %>%
  top_n(5)

other = total - sum(tidy_big_2018$value)

other_df = data.frame("other", "", "", "", 2018, other)
names(other_df) <- c("Country.Name", "Country.Code", "Series.Name", "Series.Code", "year", "value")

tidy_big_2018 <- rbind(tidy_big_2018, other_df)
tidy_big_2018$percent <- round(as.double(tidy_big_2018$value/total), 2)

tidy_big_2018 %>%
  ggplot(aes(x = "", y = value, fill = Country.Name)) + 
  geom_bar(width = 1, stat = "identity") +
  theme_minimal() +
  ggtitle("Population of the world in 2018", subtitle = {paste0('Total: ', total)})+
  theme(plot.title = element_text(size = 30,
                                  family = "Montserrat",
                                  color = pp_blue,
                                  face = "bold"),
        plot.subtitle = element_text(size = 15,
                                     family = "Calibri",
                                     color = pp_blue)) +
  theme(axis.line = element_blank(),
        plot.title = element_text(hjust=0.5),
        axis.text.x = element_blank(),
        axis.text.y = element_blank()) +
  labs(fill = "Country.Name",
       x=NULL,
       y=NULL) +
  geom_label(aes(label = percent),
             position = position_stack(vjust = 0.5),
             show.legend = FALSE) +
  scale_fill_brewer(palette="Blues")+
  coord_polar(theta = "y", start = 0) +
  guides(fill = guide_legend(title = "Country"))
  
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
tidy_big <- big %>%
  gather("year", "value", 5:55)

tidy_big$year <- as.Date(tidy_big$year, 'X%Y..YR%Y.')
tidy_big$year <- format(tidy_big$year, format = "%Y")
tidy_big = mutate(tidy_big, year=as.integer(year))

tidy_big_2018_school <- tidy_big %>%
  filter(tidy_big$year == 2018)

tidy_big_2018_school = mutate(tidy_big_2018_school, value=as.integer(value))
tidy_big_2018_school <- na.omit(tidy_big_2018_school)

tidy_big_2018_school <- tidy_big_2018_school %>%
  filter(tidy_big_2018_school$Series.Code == "SE.PRM.AGES")


tidy_big_2018_school %>%
  ggplot(aes(value)) + geom_bar(width = 1, fill = pp_blue) +
  ggtitle("Primary school starting age world distribution", subtitle = "In 2018") + 
  xlab("Age") + ylab("") +
  theme_minimal() +
  theme(plot.title = element_text(size = 30,
                                  family = "Montserrat",
                                  color = pp_blue,
                                  face = "bold"),
        plot.subtitle = element_text(size = 15,
                                     family = "Calibri",
                                     color = pp_blue))
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
tidy_big <- big %>%
  gather("year", "value", 5:55)

tidy_big$year <- as.Date(tidy_big$year, 'X%Y..YR%Y.')
tidy_big$year <- format(tidy_big$year, format = "%Y")
tidy_big = mutate(tidy_big, year=as.integer(year))

tidy_big_2018 <- tidy_big %>%
  filter(tidy_big$year == 2018)

tidy_big_2018 = mutate(tidy_big_2018, value=as.integer(value))
tidy_big_2018 <- na.omit(tidy_big_2018)

tidy_big_2018 <- tidy_big_2018 %>%
  filter(tidy_big_2018$Series.Code == "SP.POP.TOTL")

tidy_big_2018 <- tidy_big_2018 %>%
  arrange(-value)

tidy_big_2018 <- tidy_big_2018 %>%
  filter(tidy_big_2018$Country.Code != "HIC" & tidy_big_2018$Country.Code != "LIC")

tidy_big_2018_20 <- tidy_big_2018 %>%
  top_n(10)

tidy_big_2018_20 %>%
  ggplot(aes(x = Country.Name, y = value)) + geom_bar(stat = "identity", fill = pp_blue) +
  ggtitle("Countries by the population", subtitle = "In 2018") + xlab("") + ylab("") +
  scale_y_continuous(breaks=seq(0, 1392730000, 250000000), labels = function(x){paste0(x/1000000, 'M')}) +
  theme_minimal() +
  theme(plot.title = element_text(size = 30,
                                  family = "Montserrat",
                                  color = pp_blue,
                                  face = "bold"),
        plot.subtitle = element_text(size = 15,
                                     family = "Calibri",
                                     color = pp_blue),
        axis.text.x = element_text(angle=45, vjust=0.6))

#-------------------------------------------------------
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
names(bh_diff)[2] <- "Difficulty" #How difficult is to find a new block
names(bh_hrate)[2] <- "Hash Rate"  #The estimated number of tera hashes per second 
names(bh_mkpru)[2] <- "Market Price USD" #Average USD market price across major bitcoin exchanges.
names(bh_trvou)[2] <- "USD Exchange Trade Volume" #The total USD value of trading volume on major bitcoin exchanges.

blockchain <- left_join(bh_mkpru, bh_trvou, by = "Date")
blockchain <- left_join(blockchain, bh_diff, by = "Date")
blockchain <- left_join(blockchain, bh_hrate, by = "Date")

blockchain$Date <- as.Date(blockchain$Date, '%Y-%m-%d')

tidy_blockchain <- blockchain %>%
  gather("Rate", "value", 2:5)

g <- tidy_blockchain %>%
  ggplot(aes(x = Date, y = value)) + geom_line(aes(col = factor(Rate))) +
  theme_bw() +
  theme(panel.grid.major = element_blank(), 
        panel.grid.minor = element_blank(), 
        panel.border = element_blank(),
        axis.title = element_blank(),
        axis.ticks = element_blank(),
        axis.text = element_blank()) +
  theme(legend.position="None") + #Why this not desaperas :<
  scale_color_manual(name="", 
                     labels = c("", 
                                "", 
                                "",
                                ""), 
                     values = c("#2980b9", 
                                "#7fb3d5", 
                                "#aab7b8",
                                pp_blue)) +
  facet_wrap(~ Rate, scales = "free") +
  ggtitle("BITCOIN RATES", subtitle="2009 - 2021") +
  theme(plot.title = element_text(size = 30,
                                  family = "Montserrat",
                                  color = pp_blue,
                                  face = "bold"),
        plot.subtitle = element_text(size = 15,
                                     family = "Calibri",
                                     color = pp_blue))

ggplotly(g)

#-------------------------------------------------------------------------------


