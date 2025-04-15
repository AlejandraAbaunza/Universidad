package com.example.myapplication.data.remote.api

import android.util.Log
import com.example.myapplication.data.remote.model.User
import com.example.myapplication.data.remote.model.UsersList
import io.ktor.client.*
import io.ktor.client.call.body
import io.ktor.client.engine.okhttp.*
import io.ktor.client.plugins.contentnegotiation.*
import io.ktor.client.plugins.defaultRequest
import io.ktor.client.plugins.logging.*
import io.ktor.client.request.*
import io.ktor.serialization.kotlinx.json.json
import kotlinx.serialization.json.Json

class KtorApiClient {
    private val client = HttpClient (OkHttp) {
        defaultRequest {
            url("https://dummyjson.com/users")
        }

        install(Logging) {
            level = LogLevel.ALL
            logger = object : Logger {
                override fun log(message: String) {
                    Log.d("KtorApiClient", message)
                }
            }
        }


        install(ContentNegotiation) {
            json(Json {
                ignoreUnknownKeys = true
            })
        }
    }

    suspend fun getUsers(): UsersList {
        return client.get("https://dummyjson.com/users").body()
    }



}