function(input, output) {
    
        # Reactive variables
        var <- reactiveValues(grafico=NULL,legenda=NULL, tabela=NULL)
        
        rangeSerie <- reactive({
            select_time_serie(input$codigo)
        })
        
        ## Only run in interactive R sessions
        observeEvent(input$button, {
           
            # Switches tabs when clicking the button 'Show Time-Serie'
            if (input$button > 0) {
                updateTabsetPanel(session = getDefaultReactiveDomain(), "tabs", selected = "View")
            }
            else {
                updateTabsetPanel(session = getDefaultReactiveDomain(), "tabs", selected = "About")
            }
        })
        
        # To plot graphs of time-series
        output$plot <- renderPlotly({
            var$grafico <- plota_grafico(input$codigo, rangeSerie())
            var$grafico
        })
        
        # To plot table view of time-series
        output$preview<- renderPrint({
            var$tabela <- rangeSerie()
            var$tabela
        })
        
        # To summarize the time series
        output$resumo <- renderUI({
            var$legenda <- legenda(input$codigo, rangeSerie())
            var$legenda
        })
        
        # To export the plot graph to a .pdf file
        output$export_pdf = downloadHandler(
            filename = function() { paste('Time-Series', 'pdf', sep='.') },
            content = function(file) {
                pdf(file, onefile = TRUE, paper="a4")
                print(var$grafico)
                dev.off()
        })
        
        # To export the plot graph to a .png file
        output$export_png <- downloadHandler(
            filename = function() { paste0('Time-Series.png', '.png', sep='') },
            content = function(file) {
                device <- function(..., width, height) {
                    grDevices::png(..., width = width, height = height,
                                   res = 300, units = "in")
                }
                ggsave(file, plot = var$grafico, device = device)
        })
        
        # To export the time-series to a .csv file
        output$export_csv <- downloadHandler(
            filename = function() {paste0('Time-Series.csv', '.csv', sep='')},
            content = function(con) {
                suporte <- as.xts(var$tabela)
                write.zoo(suporte, con, col.names = NULL)
        })
        
        # To export the time-series to a .txt file
        output$export_txt <- downloadHandler(
            filename = function() {paste0('Time-Series.txt', '.txt', sep='')},
            content = function(con) {
                suporte <- as.xts(var$tabela)
                write.zoo(suporte, con, col.names = TRUE, sep = ",")
        })
}