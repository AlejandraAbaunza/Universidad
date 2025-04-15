package com.example.myapplication

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.ExperimentalFoundationApi
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.statusBarsPadding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.PlayArrow
import androidx.compose.material3.HorizontalDivider
import androidx.compose.material3.Icon
import androidx.compose.material3.ListItem
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.navigation.NavController
import androidx.navigation.NavType
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import androidx.navigation.navArgument
import coil3.compose.AsyncImage
import com.example.myapplication.data.remote.api.KtorApiClient
import com.example.myapplication.data.remote.model.User
import kotlinx.serialization.json.Json
import android.util.Base64
import androidx.compose.ui.text.style.TextAlign
import java.nio.charset.StandardCharsets
import android.content.Intent
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.style.TextDecoration
import androidx.compose.ui.unit.sp
import android.net.Uri
import coil3.compose.AsyncImage


class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContent {
            val navController = rememberNavController()
            NavHost(navController = navController, startDestination = "userList") {
                composable("userList") {
                    UserListScreen(navController)
                }
                composable(
                    "userDetail/{userJson}",
                    arguments = listOf(navArgument("userJson") { type = NavType.StringType })
                ) { backStackEntry ->
                    val userJsonEncoded = backStackEntry.arguments?.getString("userJson") ?: ""
                    UserDetailScreen(userJsonEncoded)
                }
            }

        }
    }
}

@Composable
fun UserDetailScreen(userJsonEncoded: String) {
    val context = LocalContext.current

    // Decodificar el JSON de Base64 a String
    val decodedJson = String(Base64.decode(userJsonEncoded, Base64.URL_SAFE or Base64.NO_WRAP), StandardCharsets.UTF_8)
    // Convertir el JSON a un objeto User
    val user = Json.decodeFromString<User>(decodedJson)

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp)
            .padding(horizontal = 32.dp),

        horizontalAlignment = Alignment.Start,
        verticalArrangement = Arrangement.Center
    ) {
        AsyncImage(
            model = user.image,
            contentDescription = null,
            modifier = Modifier
                .size(400.dp)
                .clip(CircleShape)
        )
        Text(
            text = "${user.firstName} ${user.lastName}",
            style = MaterialTheme.typography.headlineMedium,
            textAlign = TextAlign.Center,
            modifier = Modifier
                .fillMaxWidth()
                .padding(bottom = 16.dp)
        )
        Text(user.email, style = MaterialTheme.typography.bodyMedium)
        Text("Empresa: ${user.company.name}", style = MaterialTheme.typography.bodyMedium)
        Text("Teléfono: ${user.phone}", style = MaterialTheme.typography.bodyMedium,
            modifier = Modifier
                .clickable {
                    val cleanNumber = user.phone.replace(Regex("[^0-9+]"), "")
                    val dialIntent = Intent(Intent.ACTION_DIAL, Uri.parse("tel:${cleanNumber}"))
                    context.startActivity(dialIntent)
                    })
        Text("Edad: ${user.age}", style = MaterialTheme.typography.bodyMedium)
        Text("Género: ${user.gender}", style = MaterialTheme.typography.bodyMedium)
        Text("Altura: ${user.height}", style = MaterialTheme.typography.bodyMedium)
        Text("Peso: ${user.weight}", style = MaterialTheme.typography.bodyMedium)
        Text("Universidad: ${user.university}", style = MaterialTheme.typography.bodyMedium)
    }
}




// Composable para crear la lista de usuarios con un LazyColumn y un StickyHeader
@OptIn(ExperimentalFoundationApi::class)
@Composable
fun UserListScreen(navController: NavController) {
    val ktorClient = KtorApiClient()
    var users by remember { mutableStateOf(listOf<User>()) }

    LaunchedEffect(Unit) {
        users = ktorClient.getUsers().users
    }

    LazyColumn {
        stickyHeader {
            Surface(color = MaterialTheme.colorScheme.primary) {
                Header(users = users)
            }
        }

        items(users) { user ->
            UserListItem(user = user) {
                val userJson = Json.encodeToString(user)
                // Codificamos con Base64 para evitar problemas en la navegación
                val encodedJson = Base64.encodeToString(userJson.toByteArray(StandardCharsets.UTF_8), Base64.URL_SAFE or Base64.NO_WRAP)
                // Navegamos a la pantalla de detalles con el JSON codificado
                navController.navigate("userDetail/$encodedJson")
            }
        }
    }
}

// Composable para crear el header de la lista
@Composable
fun Header (users: List<User>) {
    Text(
        text = "Total de usuarios: ${users.size}",
        modifier = Modifier
            .fillMaxWidth().padding(16.dp).statusBarsPadding(),
        style = MaterialTheme.typography.headlineSmall
    )
}


// Composable para crear un item de la lista. Usamos el componente ListItem de Material3
@Composable
fun UserListItem(user: User, onClick: () -> Unit) {
    Column(
        modifier = Modifier
            .fillMaxWidth()
            .clickable(onClick = onClick) // Aquí agregamos el onClick para la acción sobre el item de usuario
    ) {
        ListItem(
            modifier = Modifier.padding(5.dp),
            leadingContent = {
                AsyncImage(
                    model = user.image,
                    contentDescription = null,
                    modifier = Modifier.size(85.dp)
                        .clip(CircleShape)
                )
            },
            headlineContent = {
                Text(
                    text = "${user.firstName} ${user.lastName}",
                    style = MaterialTheme.typography.titleMedium,
                    color = MaterialTheme.colorScheme.primary,
                    fontWeight = FontWeight.Bold)
            },
            supportingContent = {
                Text(
                    text = user.company.name,
                    style = MaterialTheme.typography.bodyMedium)
            },
            trailingContent = {
                Icon(
                    Icons.Default.PlayArrow,
                    contentDescription = null,
                    tint = Color.Gray)
            }
        )
        HorizontalDivider(thickness = 1.dp)
    }
}

@Composable
fun PhoneNumberText(phoneNumber: String) {
    val context = LocalContext.current

    Text(
        text = "Teléfono: $phoneNumber",
        fontSize = 16.sp,
        textDecoration = TextDecoration.Underline, // Para indicar que es clickeable
        modifier = Modifier.clickable {
            val dialIntent = Intent(Intent.ACTION_DIAL, Uri.parse("tel:$phoneNumber"))
            context.startActivity(dialIntent)
        }
    )
}
