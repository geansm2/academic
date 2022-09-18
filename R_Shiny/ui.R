ui <- fluidPage(    
    
    # page title
    titlePanel("Dynamic time series reports on the Brazilian economy"),
    p("Sources available: Banco Central, IBGE, Sidra, FGV"),

    # Generate a row with a sidebar
    sidebarLayout(      
        
        # Define the sidebar with one input
        sidebarPanel(
          helpText("Inform the series code that is indicated in the Search tab."),
          numericInput("codigo", "Cod of Time-Serie:", value = 0),
          actionButton("button", "Show Time-Serie"),
        ),
        
        # tabsetPanel
        mainPanel(
            tabsetPanel(
                id = "tabs",
                
                # Tab for search time-series
                tabPanel(
                    title = "Search",
                    
                    datatable(
                      ls_series, colnames = c("codigo","descricao","unidade", "periodicidade","inicio","ultimo","fonte"),
                        filter = list(position = 'top', clear = FALSE),
                        options = list(
                        search = list(regex = TRUE, caseInsensitive = TRUE, search = ''),
                        pageLength = 7)
                    )
                ),
                
                # Tab for view time-series
                tabPanel(
                    title = "View",
                    plotlyOutput("plot"),
                    htmlOutput("resumo"),
                    
                    downloadButton('export_pdf', "Download .pdf"),
                    downloadButton('export_png', "Download .png"),
                    downloadButton('export_csv', "Download .csv"),
                    downloadButton('export_txt', "Download .txt"),
                    
                    verbatimTextOutput("preview"),
                    
                ),
                
                # Appshiny explanation
                tabPanel(
                    title = "About",
                    h4("About this AppShiny"),
                    helpText("This is an academic activity of the discipline CE063B - SPECIAL TOPICS OF STATISTICS III - Dashboards, offered by the Statistics course at UFPR (Federal University of Paraná)"),
                    hr(),
                    h4("Purpose"),
                    helpText("The purpose of the application is to consult the main time series of the Brazilian economy, allowing you to graphically view, obtain summaries and export selected data to external formats (.pdf, .png, .csv, .txt)"),
                    hr(),
                    h4("Data and Time-Series"),
                    helpText("The series present in the package's database are produced by three important and respected centers: the Central Bank of Brazil (BACEN), the Brazilian Institute of Geography and Statistics (IBGE) and the Brazilian Institute of Economics of Fundação Getúlio Vargas (FGV/ IBRE). The series presented here was obited by the BETS package (BETS is an acronym for Brazilian Economic Time Series)."),
                    hr(),
                    h4("How to use"),
                    helpText("Search the time series code in the (Search) tab, enter the series code in the side panel and click on the (Show Time-Series) button"),
                    hr(),
                    h4("Contact"),
                    helpText("Gean Machado, e-mail: <gean@ufpr.br>")
                ),
            ),
        )
    ),
)