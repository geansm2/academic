library(shiny)
library(ggplot2) #for autoplot
library(plotly) #for renderPlotly
library(DT) #for datatab
library(ggfortify) #for autoplotly
library(zoo) #for export in csv/txt
library(xts) #for convert ts in xts

# Load all time-series and table use at app
load(file = "data.rda")

# Function for select a time-series view
select_time_serie <- function(n){
  if(n == 24369){serie <- ts_24369}
  if(n == 13522){serie <- ts_13522}
  if(n == 4466){serie <- ts_4466}
  if(n == 22109){serie <- ts_22109}
  if(n == 433){serie <- ts_433}
  if(n == 7326){serie <- ts_7326}
  if(n == 10810){serie <- ts_10810}
  if(n == 11777){serie <- ts_11777}
  if(n == 1208){serie <- ts_1208}
  if(n == 4447){serie <- ts_4447}
  if(n == 21864){serie <- ts_21864}
  if(n == 4189){serie <- ts_4189}
  if(n == 432){serie <- ts_432}
  if(n == 4192){serie <- ts_4192}
  return(serie)
}

# Function for plot all time-series
plota_grafico <- function(n,ts){
  indice <- match(n,lista)
  print <- autoplot(ts,
                      xlab = lista[indice,][4], ylab = lista[indice,][3],
                      main = lista[indice,][2])
  return(print)
}

# Function for sumaryze info about time-serie selected
legenda <- function(n, ts){
  indice <- match(n,lista)
  str1 <- paste("Time-Series:",lista[indice,][2])
  str2 <- paste("Number of observations:",length(ts)[1], ", Start:", start(ts)[1], ", End:", end(ts)[1], ", Min:", min(ts)[1],", Max:", max(ts)[1])
  return(HTML(paste(str1, str2, sep = '<br/>')))
}