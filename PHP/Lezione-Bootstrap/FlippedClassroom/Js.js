$(document).ready(function(){

        $("body").append("<div class=\"container-fluid\">\n" +
            "  <div class=\"row flex-nowrap\">\n" +
            "    <div class=\"col-auto col-md-3 col-xl-2 px-sm-2 px-0 bg-dark\" id=\"Card\">\n" +
            "      <div class=\"d-flex flex-column align-items-center align-items-sm-start px-3 pt-2 text-white min-vh-100\">\n" +
            "        <a href=\"Index.html\" class=\"d-flex align-items-center pb-3 mb-md-0 me-md-auto mt-2 text-white text-decoration-none border-bottom border-light w-100\">\n" +
            "          <span class=\"fs-5 d-none d-sm-inline\">Menu</span>\n" +
            "        </a>\n" +
            "        <ul class=\"nav nav-pills flex-column mb-sm-auto mb-0 align-items-center align-items-sm-start\" id=\"menu\">\n" +
            "          <li class=\"nav-item\">\n" +
            "            <a href=\"Containers.html\" class=\"nav-link align-middle px-0 link-light\">\n" +
            "              <i class=\"fs-4 bi-house\"></i><span class=\"ms-1 d-none d-sm-inline\">Containers</span>\n" +
            "            </a>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"pulsanti-form.html\" class=\"nav-link px-0 align-middle link-light\">\n" +
            "              <i class=\"fs-4 bi-table\"></i> <span class=\"ms-1 d-none d-sm-inline\">Form e pulsanti</span></a>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"testo.html\" class=\"nav-link px-0 align-middle link-light\">\n" +
            "              <i class=\"fs-4 bi-table\"></i> <span class=\"ms-1 d-none d-sm-inline\">Testi</span></a>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"layout.html\" class=\"nav-link px-0 align-middle link-light\">\n" +
            "              <i class=\"fs-4 bi-grid\"></i> <span class=\"ms-1 d-none d-sm-inline\"></span>Layout</a>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"bmp.html\" class=\"nav-link px-0 align-middle link-light\">\n" +
            "              <i class=\"fs-4 bi-grid\"></i> <span class=\"ms-1 d-none d-sm-inline\"></span>Bordi e margini.</a>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"immagini.html\" class=\"nav-link px-0 align-middle link-light\">\n" +
            "              <i class=\"fs-4 bi-grid\"></i> <span class=\"ms-1 d-none d-sm-inline\"></span>Immagini.</a>\n" +
            "          </li>\n" +
            "        </ul>\n" +
            "      </div>\n" +
            "    </div>\n" +
            "" +
            "    <div class=\"col p-0\" id='ColonnaContenuto'>\n" +
            "      <nav class=\"navbar navbar-expand-lg navbar-dark bg-dark sticky-top shadow\">\n" +
            "        <div class=\"container-sm\">\n" +
            "          <a class=\"navbar-brand\" href=\"Index.html\">Home</a>\n" +
            "          <button class=\"navbar-toggler\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#navbarSupportedContent\" aria-controls=\"navbarSupportedContent\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n" +
            "            <span class=\"navbar-toggler-icon\"></span>\n" +
            "          </button>\n" +
            "          <div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\">\n" +
            "            <ul class=\"navbar-nav me-auto mb-2 mb-lg-0\">\n" +
            "              <li class=\"nav-item\">\n" +
            "                <a class=\"nav-link active\" aria-current=\"page\" href=\"Index.html\"></a>\n" +
            "              </li>\n" +
            "              <li class=\"nav-item\">\n" +
            "                <a class=\"nav-link\" href=\"https://getbootstrap.com/docs/5.2/getting-started/introduction/\" target=\"_blank\">Documentazione</a>\n" +
            "              </li>\n" +
            "              <li class=\"nav-item\">\n" +
            "                <a class=\"nav-link\" href=\"#\">Esercizi</a>\n" +
            "              </li>\n" +
            "              <li class=\"nav-item\" id=\"AutoriLezione\">\n" +
            "                <h3 class=\"text-secondary m-0\" style='color: #a9a9a9 !important'>Lezione Bootstrap di G.C. - A.C. - D.B.</h3>\n" +
            "              </li>\n" +
            "            </ul>\n" +
            "          </div>\n" +
            "        </div>\n" +
            "      </nav>\n" +
            "    </div>\n" +
            "    <div class=\"col bg-dark\" id=\"ColonnaNera\"></div>\n" +
            "  </div>\n" +
            "</div>");

        $("#ColonnaContenuto").append("<div class='container-sm text-wrap' id='Contenuto'>"+$("#Contenuto").html()+"</div>");
        $("#Contenuto:first-child").remove();


        $("#EsempiContainers > div").click(function (){

                let Classe=$(this).find("h6").html();

                $("#DivEsempioContainers > div").remove();
                $("#DivEsempioContainers").append("<div style='background-color: lightblue;display: none;' class='"+Classe+" d-flex justify-content-center align-items-center rounded-5'><b>Sono dentro ad un "+Classe+" wow!!</b></div>");
                $("#DivEsempioContainers > div").fadeIn(500,function (){
                        $(this).animate({height: "100%"}, 500);
                });

        });

        $("#EsempiPulsanti > div").click(function (){

                $("#DivEsempioPulsanti").empty();
                $("#DivEsempioPulsanti").append("<button style='display: none;' onclick='window.open(\"https://getbootstrap.com/docs/5.2/components/buttons/\", \"_blank\");' type='button' class='"+$(this).find("h6").html()+"'>Pulsante "+$(this).find("h6").html()+"</button>");
                $("#DivEsempioPulsanti > button").fadeIn(500,function (){
                        $(this).animate({width: "90%"}, 500);
                });

        });

});
