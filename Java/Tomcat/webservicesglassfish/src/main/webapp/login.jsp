<%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 28/04/2023
  Time: 13:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<html lang="it" data-bs-theme="dark">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/ui/1.13.2/jquery-ui.min.js"
            integrity="sha256-lSjKY0/srUM9BE3dPm+c4fBo1dky2v27Gdjm2uoZaL0=" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css"
          integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A=="
          crossorigin="anonymous" referrerpolicy="no-referrer">
    <link rel="icon" type="image/x-icon" href="favicon.webp">
    <title>Login</title>
    <script>
        // Usando jquery, faccio una richiesta a post a /login, prendendo dagli input la email e la password, se ritorna
        // true, allora faccio il redirect alla home, altrimenti mostro un alert di errore
        function login() {
            $.post("login", {
                email: $("#email").val(),
                password: $("#password").val()
            }, function (data) {
                if (data === "true") {
                    window.location.href = "home.jsp";
                } else {
                    alert("Email o password sbagliati!");
                }
            });
        }
    </script>
</head>
<body class="font-monospace text-light bg-dark">
<!-- Login form -->
<div class="container mb-5">
    <div class="row justify-content-center">
        <div class="col-12 col-lg-9 col-xxl-6">
            <div class="row mt-4 mb-4">
                <div class="col">
                    <h1 class="text-center">Login</h1>
                </div>
            </div>
            <div class="row m-1 mb-5 p-4 border border-light rounded-5">
                <div class="col">
                    <div class="col-md-12">
                        <label for="email" class="form-label">Email*</label>
                        <div class="input-group">
                            <span class="input-group-text"><i class="fas fa-user"></i></span>
                            <input type="email" class="form-control" id="email" name="email" required>
                            <div class="invalid-feedback">
                                Please enter your username.
                            </div>
                        </div>
                    </div>
                    <div class="col-md-12">
                        <label for="password" class="form-label">Password*</label>
                        <div class="input-group">
                            <span class="input-group-text"><i class="fas fa-lock"></i></span>
                            <input type="password" class="form-control" id="password" name="password" required>
                            <div class="invalid-feedback">
                                Please enter your password.
                            </div>
                        </div>
                    </div>
                    <div class="col-md-12 mt-4">
                        <!-- Invio login che usa jquery negli script -->
                        <button type="submit" class="btn btn-primary w-100" onclick="login()">Login</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
</body>
</html>
