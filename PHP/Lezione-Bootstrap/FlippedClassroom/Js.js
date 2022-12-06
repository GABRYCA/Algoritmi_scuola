$(document).ready(function(){

        $("body").append("<div class=\"container-fluid\">\n" +
            "  <div class=\"row flex-nowrap\">\n" +
            "    <div class=\"col-auto col-md-3 col-xl-2 px-sm-2 px-0 bg-dark\" id=\"Card\">\n" +
            "      <div class=\"d-flex flex-column align-items-center align-items-sm-start px-3 pt-2 text-white min-vh-100\">\n" +
            "        <a href=\"/\" class=\"d-flex align-items-center pb-3 mb-md-0 me-md-auto text-white text-decoration-none\">\n" +
            "          <span class=\"fs-5 d-none d-sm-inline\">Menu</span>\n" +
            "        </a>\n" +
            "        <ul class=\"nav nav-pills flex-column mb-sm-auto mb-0 align-items-center align-items-sm-start\" id=\"menu\">\n" +
            "          <li class=\"nav-item\">\n" +
            "            <a href=\"#\" class=\"nav-link align-middle px-0\">\n" +
            "              <i class=\"fs-4 bi-house\"></i> <a href='Containers.html'><span class=\"ms-1 d-none d-sm-inline\">Containers</span></a>\n" +
            "            </a>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"pulsanti-form.html\" data-bs-toggle=\"collapse\" class=\"nav-link px-0 align-middle\">\n" +
            "              <i class=\"fs-4 bi-speedometer2\"></i> <span class=\"ms-1 d-none d-sm-inline\">Forms</span> </a>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"testo.html\" class=\"nav-link px-0 align-middle\">\n" +
            "              <i class=\"fs-4 bi-table\"></i> <span class=\"ms-1 d-none d-sm-inline\">Testi</span></a>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"#submenu2\" data-bs-toggle=\"collapse\" class=\"nav-link px-0 align-middle\">\n" +
            "              <i class=\"fs-4 bi-bootstrap\"></i> <span class=\"ms-1 d-none d-sm-inline\">Componenti</span></a>\n" +
            "            <ul class=\"collapse nav flex-column ms-1\" id=\"submenu2\" data-bs-parent=\"#menu\">\n" +
            "              <li class=\"w-100\">\n" +
            "                <a href=\"#\" class=\"nav-link px-0\"> <span class=\"d-none d-sm-inline\">Item</span> 1</a>\n" +
            "              </li>\n" +
            "              <li>\n" +
            "                <a href=\"#\" class=\"nav-link px-0\"> <span class=\"d-none d-sm-inline\">Item</span> 2</a>\n" +
            "              </li>\n" +
            "            </ul>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"layout.html\" data-bs-toggle=\"collapse\" class=\"nav-link px-0 align-middle\">\n" +
            "              <i class=\"fs-4 bi-grid\"></i> <span class=\"ms-1 d-none d-sm-inline\"></span>Layout</a>\n" +
            "            <ul class=\"collapse nav flex-column ms-1\" id=\"submenu3\" data-bs-parent=\"#menu\">\n" +
            "              <li class=\"w-100\">\n" +
            "                <a href=\"#\" class=\"nav-link px-0\"> <span class=\"d-none d-sm-inline\">Product</span> 1</a>\n" +
            "              </li>\n" +
            "              <li>\n" +
            "                <a href=\"#\" class=\"nav-link px-0\"> <span class=\"d-none d-sm-inline\">Product</span> 2</a>\n" +
            "              </li>\n" +
            "              <li>\n" +
            "                <a href=\"#\" class=\"nav-link px-0\"> <span class=\"d-none d-sm-inline\">Product</span> 3</a>\n" +
            "              </li>\n" +
            "              <li>\n" +
            "                <a href=\"#\" class=\"nav-link px-0\"> <span class=\"d-none d-sm-inline\">Product</span> 4</a>\n" +
            "              </li>\n" +
            "            </ul>\n" +
            "          </li>\n" +
            "          <li>\n" +
            "            <a href=\"#\" class=\"nav-link px-0 align-middle\">\n" +
            "              <i class=\"fs-4 bi-people\"></i> <span class=\"ms-1 d-none d-sm-inline\">Customers</span> </a>\n" +
            "          </li>\n" +
            "        </ul>\n" +
            "        <hr>\n" +
            "        <div class=\"dropdown pb-4\">\n" +
            "          <ul class=\"dropdown-menu dropdown-menu-dark text-small shadow\">\n" +
            "            <li><a class=\"dropdown-item\" href=\"#\">New project...</a></li>\n" +
            "            <li><a class=\"dropdown-item\" href=\"#\">Settings</a></li>\n" +
            "            <li><a class=\"dropdown-item\" href=\"#\">Profile</a></li>\n" +
            "            <li>\n" +
            "              <hr class=\"dropdown-divider\">\n" +
            "            </li>\n" +
            "            <li><a class=\"dropdown-item\" href=\"#\">Sign out</a></li>\n" +
            "          </ul>\n" +
            "        </div>\n" +
            "      </div>\n" +
            "    </div>\n" +
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
            "                <h3 class=\"text-secondary m-0\">Lezione Bootstrap di G.C. - A.C. - D.B.</h3>\n" +
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

                $("#DivEsempioContainers").empty();
                $("#DivEsempioContainers").append("<div style='background-color: lightblue;height: 100%;' class='"+$(this).find("h6").html()+" d-flex justify-content-center align-items-center'><b>Sono dentro ad un "+$(this).find("h6").html()+" wow!!</b></div>");

        });

});
