package com.example.myapplication.data.remote.model

import kotlinx.serialization.Serializable

@Serializable
data class UsersList(
    val users: List<User>
)
